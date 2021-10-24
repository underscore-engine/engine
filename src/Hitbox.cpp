#include "Hitbox.hpp"

Direction CollisionFix::getDirectionFromVector(sf::Vector2f v)
{
	if (v.x == 0)
	{
		if (v.y == 0)
			return Direction::none;
		return v.y > 0 ? Direction::down : Direction::up;
	}
	if (v.y != 0)
		return Direction::diagonal;
	return v.x > 0 ? Direction::right : Direction::left;
}

Direction CollisionFix::h1_direction()
{
	return getDirectionFromVector(h1_displacement);
}

Direction CollisionFix::h2_direction()
{
	return getDirectionFromVector(h2_displacement);
}

Hitbox::Hitbox(sf::Vector2f _pos, sf::Vector2f _size = sf::Vector2f(0, 0)) :
	Physics { _pos }
{
	size = _size;
}

sf::RectangleShape Hitbox::get_hitbox_outline()
{
	sf::RectangleShape rect;
	rect.setSize(size);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(5);
	rect.setPosition(pos.x, pos.y);
	return rect;
}

bool Hitbox::overlaps(Hitbox h)
{
	// If one rectangle is on left side of other
	if (pos.x + size.x <= h.pos.x || h.pos.x + h.size.x <= pos.x)
		return false;

	// If one rectangle is on below the other
	if (pos.y + size.y <= h.pos.y || h.pos.y + h.size.y <= pos.y)
		return false;

	return true;
}

// ========== OVERLAP CORRECTION LOGIC ==========
CollisionFix Hitbox::calculateHitboxOverlap(Hitbox other)
{
	const float* x_displacements = calculateHitboxOverlapX(other);
	const float* y_displacements = calculateHitboxOverlapY(other);

	const float x_disp_mag = std::abs(x_displacements[0]) + std::abs(x_displacements[1]);
	const float y_disp_mag = std::abs(y_displacements[0]) + std::abs(y_displacements[1]);

	sf::Vector2f h1_dsp;
	sf::Vector2f h2_dsp;

	if (x_disp_mag == 0)
	{
		h1_dsp = sf::Vector2f(0, y_displacements[0]);
		h2_dsp = sf::Vector2f(0, y_displacements[1]);
	}
	else if (y_disp_mag == 0)
	{
		h1_dsp = sf::Vector2f(x_displacements[0], 0);
		h2_dsp = sf::Vector2f(x_displacements[1], 0);
	}
	else if (x_disp_mag > y_disp_mag)
	{
		h1_dsp = sf::Vector2f(0, y_displacements[0]);
		h2_dsp = sf::Vector2f(0, y_displacements[1]);
	}
	else
	{
		h1_dsp = sf::Vector2f(x_displacements[0], 0);
		h2_dsp = sf::Vector2f(x_displacements[1], 0);
	}

	return { h1_dsp, h2_dsp };
}

float* Hitbox::calculateHitboxOverlapX(Hitbox other)
{
	const float gross_velocity = std::abs(vel.x) + std::abs(other.vel.x);
	if (gross_velocity == 0)
	{
		static float ds[2] = { 0.f, 0.f };
		return ds;
	}

	const bool am_i_left = pos.x < other.pos.x;
	const float meeting_side = am_i_left ? pos.x + size.x : pos.x;
	const float other_meeting_side = am_i_left ? other.pos.x : other.pos.x + other.size.x;
	const float meeting_sides_dist = std::abs(meeting_side - other_meeting_side);

	static float x_displacements[2];
	x_displacements[0] = (am_i_left ? -1 : 1) * (meeting_sides_dist * std::abs(vel.x) / gross_velocity);
	x_displacements[1] = (am_i_left ? 1 : -1) * (meeting_sides_dist * std::abs(other.vel.x) / gross_velocity);

	return x_displacements;
}

float* Hitbox::calculateHitboxOverlapY(Hitbox other)
{
	const float gross_velocity = std::abs(vel.y) + std::abs(other.vel.y);
	if (gross_velocity == 0)
	{
		static float ds[2] = { 0.f, 0.f };
		return ds;
	}

	const bool am_i_above = pos.y < other.pos.y;
	const float meeting_side = am_i_above ? pos.y + size.y : pos.y;
	const float other_meeting_side = am_i_above ? other.pos.y : other.pos.y + other.size.y;
	const float meeting_sides_dist = std::abs(meeting_side - other_meeting_side);

	static float y_displacements[2];
	y_displacements[0] = (am_i_above ? -1 : 1) * (meeting_sides_dist * std::abs(vel.y) / gross_velocity);
	y_displacements[1] = (am_i_above ? 1 : -1) * (meeting_sides_dist * std::abs(other.vel.y) / gross_velocity);

	return y_displacements;
}

void Hitbox::resetVelOnCollision(Direction dir)
{
	switch (dir)
	{
		case Direction::right:
		case Direction::left:
			vel.x = 0;
			break;

		case Direction::down:
		case Direction::up:
			vel.y = 0;
			break;

		default:
			break;
	}
}

CollisionFix Hitbox::correctHitboxOverlap(Hitbox other)
{
	CollisionFix fix = calculateHitboxOverlap(other);

	pos += fix.h1_displacement;
	other.pos += fix.h2_displacement;

	resetVelOnCollision(fix.h1_direction());
	other.resetVelOnCollision(fix.h2_direction());

	return fix;
}
// ========== END OVERLAP CORRECTION LOGIC ==========
