#ifndef MenuButton_H
#define MenuButton_H

class MenuButton
{
private:
	sf::Texture texture;

public:
	MenuButton();
	float width;
	float height;
	float scale;
	float window_scale_x;
	float window_scale_y;
	sf::Sprite sprite;
	sf::Vector2f position;
	void setPosition(float width, float height, float window_scale_x, float window_scale_y);
};

#endif