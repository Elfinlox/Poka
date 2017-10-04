#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Platform.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1366 ,768), "SFML test", sf::Style::Fullscreen);

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 576.0f));
    sf::Texture playerTexture, thorntex, gameovertex, gamewintex, eeltex, squidtex, deviatex, nightfintex;
    playerTexture.loadFromFile("pokarla.png");
    thorntex.loadFromFile("thorn.png");
    gameovertex.loadFromFile("gameoverscreen.png");
    gamewintex.loadFromFile("gamewinscreen.png");
    eeltex.loadFromFile("eel.png");
    squidtex.loadFromFile("squid.png");
    deviatex.loadFromFile("deviate.png");
    nightfintex.loadFromFile("nightfin.png");


    sf::SoundBuffer buffer;
    buffer.loadFromFile("Level.wav");
    sf::Sound levelmusic;
    levelmusic.setBuffer(buffer);
    levelmusic.play();





    Player player(&playerTexture, sf::Vector2u(3,4), sf::Vector2f(50.0f,50.0f), 0.2f, 100.0f, 120.0f);


    float dTime=0.0f;
    sf::Clock clock;

    sf::Texture platformtex;
    platformtex.loadFromFile("platform.png");

    sf::Texture aryotex;
    aryotex.loadFromFile("aryo.png");

    const int n = 12;
    Platform platform[n];
    platform[0] = Platform(&platformtex, sf::Vector2f(50.0f, 768.0f), sf::Vector2f(0.0f, 768.0f/2));//leftwall
    platform[1] = Platform(&platformtex, sf::Vector2f(1366.0f, 50.0f), sf::Vector2f(1366.0f/2, 0.0f));//topwall
    platform[2] = Platform(&platformtex, sf::Vector2f(50.0f, 768.0f), sf::Vector2f(1366.0f, 768.0f/2));//rightwall
    platform[3] = Platform(&platformtex, sf::Vector2f(1366.0f, 50.0f), sf::Vector2f(1366.0f/2, 768.0f));//bottomwall

    platform[4] = Platform(&platformtex, sf::Vector2f(170.0f, 35.0f), sf::Vector2f(110.0f, 170.0f));

    platform[5] = Platform(&platformtex, sf::Vector2f(120.0f, 35.0f), sf::Vector2f(300.0f, 290.0f));

    platform[6] = Platform(&platformtex, sf::Vector2f(300.0f, 35.0f), sf::Vector2f(600.0f, 410.0f));//mid block

    platform[7] = Platform(&platformtex, sf::Vector2f(100.0f, 35.0f), sf::Vector2f(300.0f, 500.0f));//soft left

    platform[8] = Platform(&platformtex, sf::Vector2f(100.0f, 35.0f), sf::Vector2f(920.0f, 310.0f));//soft right

    platform[9] = Platform(&platformtex, sf::Vector2f(100.0f, 35.0f), sf::Vector2f(700.0f, 200.0f));//first jump

    platform[10] = Platform(&platformtex, sf::Vector2f(100.0f, 35.0f), sf::Vector2f(1090.0f, 230.0f));//right up

    platform[11] = Platform(&platformtex, sf::Vector2f(100.0f, 35.0f), sf::Vector2f(1090.0f, 500.0f));//right down

    Platform thorn(&thorntex, sf::Vector2f(1366.0f, 100.0f), sf::Vector2f(1366.0f/2, 718.0f));

    Platform eel(&eeltex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f(300.0f, 464.0f));
    Platform squid(&squidtex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f(700.0f, 164.0f));
    Platform deviate(&deviatex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f(1090.0f, 194.0f));
    Platform nightfin(&nightfintex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f(1090.0f, 458.0f));


    bool hasEel = false, hasSquid = false, hasDeviate = false, hasNightfin = false;







    Platform background (nullptr, sf::Vector2f(1366.0f - 50.0f, 768.0f - 50.0f), sf::Vector2f(1366.0f/2, 768.0f/2));

    while (window.isOpen())
    {

        dTime = clock.restart().asSeconds();
        if(dTime > 1.0f/30.0f)
            dTime = 1.0f/30.0f;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }



        player.update(dTime);

        sf::Vector2f direction;

        Platform gameover(&gameovertex, sf::Vector2f(1024.0f, 500.0f), sf::Vector2f(player.GetPosition()));
        Platform gamewin(&gamewintex, sf::Vector2f(1024.0f, 500.0f), sf::Vector2f(player.GetPosition()));
        Platform aryo(&aryotex, sf::Vector2f(1024.0f, 576.0f), sf::Vector2f(player.GetPosition()));


        for(int i = 0; i < n; i++)
            {
                    if(i == 7 || i == 8)
                    {
                        platform[i].GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f);
                        if(platform[i].GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f));
                            player.OnCollision(direction);
                    }

                    else
                    {
                        platform[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f);
                        if(platform[i].GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f));
                            player.OnCollision(direction);
                    }
            }

        if(eel.GetCollider().CheckCollision(player.GetCollider(),direction, 1.0f))
           hasEel = true;

        if(squid.GetCollider().CheckCollision(player.GetCollider(),direction, 1.0f))
            hasSquid = true;

        if(deviate.GetCollider().CheckCollision(player.GetCollider(),direction, 1.0f))
            hasDeviate = true;

        if(nightfin.GetCollider().CheckCollision(player.GetCollider(),direction, 1.0f))
            hasNightfin = true;





        view.setCenter(player.GetPosition());
        window.setView(view);
        window.clear(sf::Color(105,33,143));
        background.draw(window);
        thorn.draw(window);
        player.draw(window);


        squid.draw(window);
        deviate.draw(window);
        nightfin.draw(window);

        for(int i=0; i < n; i++)
            platform[i].draw(window);

        if(thorn.GetCollider().CheckCollision(player.GetCollider(),direction, 1.0f))
        {
                gameover.draw(window);
                player.cannotMove();
        }

        if(hasEel == true && hasSquid == true && hasDeviate == true && hasNightfin == true)
        {
            gamewin.draw(window);
            aryo.draw(window);
            player.cannotMove();

        }



//***********************************************************************************************


        if(hasEel == true)
        {
            eel = Platform(&eeltex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f((player.GetPosition().x + 1024.0f/2) - 18.0f, (player.GetPosition().y - 576.0f/2) + 18.0f));
            eel.draw(window);
        }
        else
            eel.draw(window);

        if(hasSquid == true)
        {
            squid = Platform(&squidtex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f((player.GetPosition().x + 1024.0f/2) - 18.0f - (1 * 36.0f), (player.GetPosition().y - 576.0f/2) + 18.0f));
            squid.draw(window);
        }
        else
            squid.draw(window);

        if(hasDeviate == true)
        {
            deviate = Platform(&deviatex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f((player.GetPosition().x + 1024.0f/2) - 18.0f - (2 * 36.0f), (player.GetPosition().y - 576.0f/2) + 18.0f));
            deviate.draw(window);
        }
        else
            deviate.draw(window);

        if(hasNightfin == true)
        {
            nightfin = Platform(&nightfintex, sf::Vector2f(36.0f, 36.0f), sf::Vector2f((player.GetPosition().x + 1024.0f/2) - 18.0f - (3 * 36.0f), (player.GetPosition().y - 576.0f/2) + 18.0f));
            nightfin.draw(window);
        }
        else
            nightfin.draw(window);






        window.display();

    }



    return 0;
}
