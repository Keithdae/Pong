#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>


enum GameState{
    PvP,
    PvIA,
    Menu
};

int main()
{
    std::ostringstream out1;
    std::ostringstream out2;

    GameState state = Menu;

    // Creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(720, 480), "Pong");
    window.setFramerateLimit(60);


    // Les sons op ici
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer2;
    sf::SoundBuffer buffer3;
    if(!buffer.loadFromFile("puuuum.wav"))
        std::cout << "blah blah erreur" << std::endl;
    if(!buffer2.loadFromFile("tooo.wav"))
        std::cout << "blah blah erreur" << std::endl;
    if(!buffer3.loadFromFile("deeerp.wav"))
        std::cout << "blah blah erreur" << std::endl;
    sf::Sound raquetteHit;
    raquetteHit.setBuffer(buffer);
    sf::Sound wallHit;
    wallHit.setBuffer(buffer2);
    sf::Sound point;
    point.setBuffer(buffer3);




    // Chargement du background
    sf::Texture textureBackground;
    if(!textureBackground.loadFromFile("background.jpg"))
        std::cout << "Erreur chargement textureBackground" << std::endl;
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);



    // Chargement des raquettes
    sf::Texture textureRaquette;
    if(!textureRaquette.loadFromFile("raquette.jpg"))
        std::cout << "Erreur chargement textureRaquette" << std::endl;
    sf::Sprite spriteRaquette1;
    sf::Sprite spriteRaquette2;
    spriteRaquette1.setTexture(textureRaquette);
    spriteRaquette2.setTexture(textureRaquette);



    // Placement initial des raquettes
    spriteRaquette1.setPosition(sf::Vector2f(20,240));
    spriteRaquette2.setPosition(sf::Vector2f(700,240));


    // Chargement du filet
    sf::Texture textureFilet;
    if(!textureFilet.loadFromFile("filet.jpg"))
        std::cout << "Erreur chargement textureFilet" << std::endl;
    sf::Sprite spriteFilet;
    spriteFilet.setTexture(textureFilet);

    // Placement filet
    spriteFilet.setPosition(sf::Vector2f(360,5));


    // Chargement de la balle
    sf::Texture textureBalle;
    if(!textureBalle.loadFromFile("balle.jpg"))
        std::cout << "Erreur chargement textureBalle" << std::endl;
    sf::Sprite spriteBalle;
    spriteBalle.setTexture(textureBalle);


    // Placement balle
    spriteBalle.setPosition(sf::Vector2f(280,160));


    // Variables pour le déplacement de la balle (Vitesse)
    float vitX = 1.4;
    float vitY = 1.4;


    // Chargement de la police pour le score
    sf::Font font;
    if(!font.loadFromFile("EROTC___.ttf"))
        std::cout << "Erreur chargement font EROTICA" << std::endl;
    sf::Text scoreJ1;
    sf::Text scoreJ2;
    scoreJ1.setFont(font);
    scoreJ2.setFont(font);
    scoreJ1.setColor(sf::Color::White);
    scoreJ2.setColor(sf::Color::White);
    scoreJ1.setCharacterSize(40);
    scoreJ2.setCharacterSize(40);
    scoreJ1.setPosition(300, 15);
    scoreJ2.setPosition(420, 15);


    // Chargement du menu
    sf::Texture textureMenu;
    if(!textureMenu.loadFromFile("menu.jpg"))
        std::cout << "Erreur chargement menu" << std::endl;
    sf::Sprite spriteMenu;
    spriteMenu.setTexture(textureMenu);



    // Variables de score
    int scoreJ1Int = 0;
    int scoreJ2Int = 0;

    out1 << scoreJ1Int;
    scoreJ1.setString(out1.str());
    out2 << scoreJ2Int;
    scoreJ2.setString(out2.str());

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed :
                    window.close();
                    break;

                case sf::Event::KeyReleased :
                    if(event.key.code == sf::Keyboard::P)
                    {
                        if(state == Menu)
                            state = PvP;
                    }
                    else if(event.key.code == sf::Keyboard::I)
                    {
                        if(state == Menu)
                            state = PvIA;
                    }

                default :
                    break;
            }
        }

        window.clear();

        if(state == Menu)
        {
            window.draw(spriteMenu);
        }
        else
        {
            std::ostringstream out3;
            std::ostringstream out4;


            // Joueur 1
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if(spriteRaquette1.getPosition().y < 430)
                {
                    spriteRaquette1.setPosition(spriteRaquette1.getPosition().x, spriteRaquette1.getPosition().y + 3);
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if(spriteRaquette1.getPosition().y > 0)
                {
                    spriteRaquette1.setPosition(spriteRaquette1.getPosition().x, spriteRaquette1.getPosition().y - 3);
                }
            }


            if(state == PvP)
            {
                // Joueur 2
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    if(spriteRaquette2.getPosition().y < 430)
                    {
                        spriteRaquette2.setPosition(spriteRaquette2.getPosition().x, spriteRaquette2.getPosition().y + 3);
                    }
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    if(spriteRaquette2.getPosition().y > 0)
                    {
                        spriteRaquette2.setPosition(spriteRaquette2.getPosition().x, spriteRaquette2.getPosition().y - 3);
                    }
                }
            }
            else if(state == PvIA)
            {
                // code IA ici plox
                if(spriteRaquette2.getPosition().y + 25 < spriteBalle.getPosition().y)
                {
                    spriteRaquette2.setPosition(spriteRaquette2.getPosition().x, spriteRaquette2.getPosition().y + 3);
                }
                if(spriteRaquette2.getPosition().y + 25 > spriteBalle.getPosition().y)
                {
                    spriteRaquette2.setPosition(spriteRaquette2.getPosition().x, spriteRaquette2.getPosition().y - 3);
                }
            }





            window.draw(spriteBackground);
            window.draw(spriteFilet);

            window.draw(spriteRaquette1);
            window.draw(spriteRaquette2);



            // On actualise la position de la balle, puis on draw

            if(spriteBalle.getPosition().y > 475 || spriteBalle.getPosition().y < 0)
            {
                vitY = vitY * -1;
                wallHit.play();
            }

            spriteBalle.setPosition(spriteBalle.getPosition().x + vitX, spriteBalle.getPosition().y + vitY);

            sf::FloatRect rectBalle = spriteBalle.getGlobalBounds();
            sf::FloatRect rectRaquette1 = spriteRaquette1.getGlobalBounds();
            sf::FloatRect rectRaquette2 = spriteRaquette2.getGlobalBounds();

            if(rectBalle.intersects(rectRaquette1) || rectBalle.intersects(rectRaquette2))
            {
                vitX = vitX * -1;
                vitX *= 1.2;
                vitY *= 1.2;
                raquetteHit.play();
            }

            window.draw(spriteBalle);

            if(spriteBalle.getPosition().x > 780)
            {
                scoreJ1Int++;
                spriteBalle.setPosition(sf::Vector2f(280,160));
                out3 << scoreJ1Int;
                scoreJ1.setString(out3.str());
                point.play();
                vitX = 1.4;
                vitY = 1.4;
            }
            if(spriteBalle.getPosition().x < 0)
            {
                scoreJ2Int++;
                spriteBalle.setPosition(sf::Vector2f(280,160));
                out4 << scoreJ2Int;
                scoreJ2.setString(out4.str());
                point.play();
                vitX = 1.4;
                vitY = 1.4;
            }


            window.draw(scoreJ1);
            window.draw(scoreJ2);
        }

        window.display();
    }


    return 0;
}
