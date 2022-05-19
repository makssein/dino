#include <myHeaders.h>

class myText {
public:
    myText(sf::Font font, std::string textString, int size, sf::Color color, int position_x, int poxition_y);
    ~myText();
    sf::Text* get() {return m_text;}
    void newString(std::string textString);
private:
    sf::Font m_font;
    std::string m_textString;
    int m_size, m_position_x, m_position_y;
    sf::Color m_color;
    sf::Text* m_text;
};