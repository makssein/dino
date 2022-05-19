#include <myText.hpp>

myText::myText(sf::Font font, std::string textString, int size, sf::Color color, int position_x, int position_y) {
    m_font = font;
    m_textString = textString;
    m_size = size;
    m_color = color;
    m_position_x = position_x;
    m_position_y = position_y;

    m_text = new sf::Text;
    m_text->setFont(m_font);
    m_text->setString(m_textString);
    m_text->setCharacterSize(m_size);
    m_text->setFillColor(m_color);
    m_text->setPosition(m_position_x,m_position_y);
}
myText::~myText() {delete m_text;}

void myText::newString(std::string textString) {
    m_textString = textString;
    m_text->setString(m_textString);
}