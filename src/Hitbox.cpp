#include "Hitbox.hpp"

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
	if (pos.x + size.x <= h.pos.x || h.pos.x + h.size.x <= pos.x){
		return false;
	}
	// If one rectangle is on below the other
	//Sets the not grounded value to false, meaning the player is on the ground and can jump
	else if (pos.y + size.y <= h.pos.y || h.pos.y + h.size.y <= pos.y){
		notGrounded = true;
		return false;
	}
	//As a default sets the not grounded value to true, meaning the player is in the air and can't jump
	else{
		notGrounded = false;
		return true;
	}
}

// ========== OVERLAP CORRECTION LOGIC ==========
sf::Vector2f* Hitbox::correctHitboxOverlap(sf::Vector2f* new_vels, Hitbox other, sf::Vector2f _vel, sf::Vector2f other_vel)
{
	const float* x_displacements = correctHitboxOverlapX(other, _vel.x, other_vel.x);
	const float* y_displacements = correctHitboxOverlapY(other, _vel.y, other_vel.y);

	const float x_disp_mag = std::abs(x_displacements[0]) + std::abs(x_displacements[1]);
	const float y_disp_mag = std::abs(y_displacements[0]) + std::abs(y_displacements[1]);

	if (x_disp_mag < y_disp_mag && x_disp_mag != 0)
	{
		new_vels[0] = sf::Vector2f(x_displacements[0], 0);
		new_vels[1] = sf::Vector2f(x_displacements[1], 0);
	}
	else if (y_disp_mag != 0)
	{
		new_vels[0] = sf::Vector2f(0, y_displacements[0]);
		new_vels[1] = sf::Vector2f(0, y_displacements[1]);
		vel.y = 0; // PLEASE CHANGE THIS LATER
	}
	else
	{
		new_vels[0] = sf::Vector2f(x_displacements[0], y_displacements[0]);
		new_vels[1] = sf::Vector2f(x_displacements[1], y_displacements[1]);
		vel.y = 0; // PLEASE CHANGE THIS LATER
	}

	return new_vels;
}

float* Hitbox::correctHitboxOverlapX(Hitbox other, float dx, float other_dx)
{
	const float gross_velocity = std::abs(dx) + std::abs(other_dx);
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
	x_displacements[0] = (am_i_left ? -1 : 1) * (meeting_sides_dist * std::abs(dx) / gross_velocity);
	x_displacements[1] = (am_i_left ? 1 : -1) * (meeting_sides_dist * std::abs(other_dx) / gross_velocity);

	return x_displacements;
}

float* Hitbox::correctHitboxOverlapY(Hitbox other, float dy, float other_dy)
{
	const float gross_velocity = std::abs(dy) + std::abs(other_dy);
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
	y_displacements[0] = (am_i_above ? -1 : 1) * (meeting_sides_dist * std::abs(dy) / gross_velocity);
	y_displacements[1] = (am_i_above ? 1 : -1) * (meeting_sides_dist * std::abs(other_dy) / gross_velocity);

	return y_displacements;
}
// ========== END OVERLAP CORRECTION LOGIC ==========
