#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
int main()
{
    int m1p = 99, m2p = 99, m3p = 99;
    int music = 0, menu = 0, score = 0;
    sf::Clock Clock;
    float endtime = 0;
    float time1=0;
    float timemon = 0;
    float timemonrun = 0;
    float warpcooldown = 0;
    float itemspeedtime = 0;
    float itemspeed = 0;
    sf::RenderWindow window(sf::VideoMode(672, 820), "DragMan");
    sf::SoundBuffer mission;
    if (!mission.loadFromFile("song/mission.ogg"));
    sf::Sound mission01;
    mission01.setBuffer(mission);
    mission01.setVolume(40);
    mission01.setLoop(true);
    //////Win
    sf::Texture win;
    if (!win.loadFromFile("image/images-removebg-preview.png"))
    {
        std::cout << "Win Load failed" << std::endl;
    }
    sf::Sprite winn;
    winn.setTexture(win);
    winn.setPosition(80.f, 200.f);
    winn.setScale(2.f, 2.f);
    //////Lose
    sf::Texture lose;
    if (!lose.loadFromFile("image/loser-hand-sign-vector-146404601-removebg-preview.png"))
    {
        std::cout << "Loser Load failed" << std::endl;
    }
    sf::Sprite loser;
    loser.setTexture(lose);
    loser.setPosition(100.f, 150.f);
    //////Logo
    sf::Texture Logo;
    if (!Logo.loadFromFile("image/Untitled.png"))
    {
        std::cout << "Logo Load failed" << std::endl;
    }
    sf::Sprite Logoim;
    Logoim.setTexture(Logo);
    Logoim.setPosition(160.f, 160.f);
    sf::Texture Cre;
    if (!Cre.loadFromFile("image/credit.png"))
    {
        std::cout << "Credit Load failed" << std::endl;
    }
    sf::Sprite credit;
    credit.setTexture(Cre);
    credit.setPosition(-15.f, 0.f);
    credit.setScale(0.8f, 0.8f);
    //////start
    sf::Texture start;
    if (!start.loadFromFile("image/start.png"))
    {
        std::cout << "Start Button Load failed" << std::endl;
    }
    sf::Sprite Startbut;
    Startbut.setTexture(start);
    Startbut.setPosition(184.f, 350.f);
    Startbut.setScale(1.5f, 1.5f);
    //////control
    sf::Texture contr;
    if (!contr.loadFromFile("image/contr.png"))
    {
        std::cout << "Control Button Load failed" << std::endl;
    }
    sf::Sprite Contrbut;
    Contrbut.setTexture(contr);
    Contrbut.setPosition(184.f, 450.f);
    Contrbut.setScale(1.5f, 1.5f);
    ////// exit
    sf::Texture exit;
    if (!exit.loadFromFile("image/exit.png"))
    {
        std::cout << "Exit Button Load failed" << std::endl;
    }
    sf::Sprite exitbut;
    exitbut.setTexture(exit);
    exitbut.setPosition(184.f, 550.f);
    exitbut.setScale(1.5f, 1.5f);
    sf::Texture cont;
    if (!cont.loadFromFile("image/cont.png"))
    {
        std::cout << "Control Image Load failed" << std::endl;
    }
    sf::Sprite controlimage;
    controlimage.setTexture(cont);
    controlimage.setPosition(50.f, 50.f);
    controlimage.setScale(.7f, .7f);
    ////// Texture
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("image/playercharacter.png"))
    {
        std::cout << "Load failed" << std::endl;
    }
    ////// Sprite
    sf::Sprite shapeSprite;
    shapeSprite.setTexture(playerTexture);
    shapeSprite.setTextureRect(sf::IntRect(65, 1, 19, 25));
    shapeSprite.setPosition({ 324.f,764.f });
    shapeSprite.setScale(sf::Vector2f(1.4f, 1.4f));
	int animationFrame = 0;
    ////// Texture Map
    sf::Texture MapTexture;
    if (!MapTexture.loadFromFile("image/bg.png"))
    {
        std::cout << "Load Map Failed" << std::endl;
    }
    ///// Sprite Map
    sf::Sprite MapSprite;
    MapSprite.setTexture(MapTexture);
    MapSprite.setTextureRect(sf::IntRect(0, 0, 224, 256));
    MapSprite.setPosition({ 0.f,50.f });
    MapSprite.setScale(sf::Vector2f(3.f, 3.f));
    ///// LeftprotalTexture 
    sf::Texture leftportaltexture;
    if (!leftportaltexture.loadFromFile("image/warpportalleft.png"))
    {
        std::cout << "Load Portalleft Failed" << std::endl;
    }
    ///// Sprite leftprotal
    sf::Sprite leftportal;
    leftportal.setTexture(leftportaltexture);
    leftportal.setTextureRect(sf::IntRect(10, 10, 348, 348));
    leftportal.setPosition({0.f,400.f});
    leftportal.setScale(sf::Vector2f(.12f, .12f));
    ///// RightprotalTexture 
    sf::Texture rightportaltexture;
    if (!rightportaltexture.loadFromFile("image/warpportalright.jpg"))
    {
        std::cout << "Load PortalRight Failed" << std::endl;
    }
    ///// Sprite rightprotal
    sf::Sprite rightportal;
    rightportal.setTexture(rightportaltexture);
    rightportal.setTextureRect(sf::IntRect(0, 0, 348, 348));
    rightportal.setPosition({ 630.f,400.f });
    rightportal.setScale(sf::Vector2f(.12f, .12f));
    ///// CloseLeftportalTexture
    sf::Texture closeleftportaltexture;
    if (!closeleftportaltexture.loadFromFile("image/lefttportalclose.png"))
    {
        std::cout << "Load ClosePortalleft Failed" << std::endl;
    }
    ///// Sprite closeleftprotal
    sf::Sprite closeleftportal;
    closeleftportal.setTexture(closeleftportaltexture);
    closeleftportal.setTextureRect(sf::IntRect(0, 0, 466, 535));
    closeleftportal.setPosition({ -10.f,400.f });
    closeleftportal.setScale(sf::Vector2f(.09f, .08f));
    ///// CloseRightportalTexture
    sf::Texture closerightportaltexture;
    if (!closerightportaltexture.loadFromFile("image/rightportalclose.png"))
    {
        std::cout << "Load ClosePortalRight Failed" << std::endl;
    }
    ///// Sprite closerightprotal
    sf::Sprite closerightportal;
    closerightportal.setTexture(closeleftportaltexture);
    closerightportal.setTextureRect(sf::IntRect(0, 0, 466, 535));
    closerightportal.setPosition({ 630.f,400.f });
    closerightportal.setScale(sf::Vector2f(.09f, .08f));
    /////Rectangles
        sf::RectangleShape rec1(sf::Vector2f(74.f, 44.f));
        rec1.setPosition(58.f, 139.f);
        rec1.setFillColor(sf::Color::Blue); //ready
        sf::RectangleShape rec2(sf::Vector2f(97.f, 44.f));
        rec2.setPosition(180.f, 139.f);
        rec2.setFillColor(sf::Color::Blue); //ready
        sf::RectangleShape rec3(sf::Vector2f(25.f, 96.f));
        rec3.setPosition(324.f, 86.f);
        rec3.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec4(sf::Vector2f(97.f, 44.f));
        rec4.setPosition(395.f, 139.f);
        rec4.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec5(sf::Vector2f(74.f, 44.f));
        rec5.setPosition(540.f, 139.f);
        rec5.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec6(sf::Vector2f(74.f, 20.f));
        rec6.setPosition(58.f, 234.f);
        rec6.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec7(sf::Vector2f(169.f, 20.f));
        rec7.setPosition(251.f, 234.f);
        rec7.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec8(sf::Vector2f(74.f, 20.f));
        rec8.setPosition(540.f, 234.f);
        rec8.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec11(sf::Vector2f(25.f, 165.f));
        rec11.setPosition(180.f, 234.f);
        rec11.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec13(sf::Vector2f(25.f, 165.f));
        rec13.setPosition(467.f, 234.f);
        rec13.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec9(sf::Vector2f(70.f, 20.f));
        rec9.setPosition(205.f, 306.f);
        rec9.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec10(sf::Vector2f(68.f, 20.f));
        rec10.setPosition(398.f, 306.f);
        rec10.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec12(sf::Vector2f(25.f, 72.f));
        rec12.setPosition(324.f, 254.f);
        rec12.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec14(sf::Vector2f(120.f, 93.f));
        rec14.setPosition(12.f, 306.f);
        rec14.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec15(sf::Vector2f(120.f, 93.f));
        rec15.setPosition(540.f, 306.f);
        rec15.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec16(sf::Vector2f(120.f, 93.f));
        rec16.setPosition(12.f, 449.f);
        rec16.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec21(sf::Vector2f(120.f, 93.f));
        rec21.setPosition(540.f, 449.f);
        rec21.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec17(sf::Vector2f(25.f, 93.f));
        rec17.setPosition(180.f, 449.f);
        rec17.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec20(sf::Vector2f(25.f, 93.f));
        rec20.setPosition(467.f, 449.f);
        rec20.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec18(sf::Vector2f(169.f, 21.f));
        rec18.setPosition(251.f, 521.f);
        rec18.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec19(sf::Vector2f(25.f, 72.f));
        rec19.setPosition(324.f, 542.f);
        rec19.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec22(sf::Vector2f(70.f, 21.f));
        rec22.setPosition(62.f, 593.f);
        rec22.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec24(sf::Vector2f(95.f, 21.f));
        rec24.setPosition(180.f, 593.f);
        rec24.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec25(sf::Vector2f(94.f, 21.f));
        rec25.setPosition(398.f, 593.f);
        rec25.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec27(sf::Vector2f(74.f, 21.f));
        rec27.setPosition(540.f, 593.f);
        rec27.setFillColor(sf::Color::Blue);//ready
        sf::RectangleShape rec23(sf::Vector2f(24.f, 73.f));
        rec23.setPosition(108.f, 614.f);
        rec23.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec26(sf::Vector2f(25.f, 73.f));
        rec26.setPosition(540.f, 614.f);
        rec26.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec28(sf::Vector2f(48.f, 22.f));
        rec28.setPosition(12.f, 665.f);
        rec28.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec35(sf::Vector2f(48.f, 22.f));
        rec35.setPosition(612.f, 665.f);
        rec35.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec31(sf::Vector2f(169.f, 22.f));
        rec31.setPosition(251.f, 665.f);
        rec31.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec32(sf::Vector2f(25.f, 72.f));
        rec32.setPosition(324.f, 686.f);
        rec32.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec30(sf::Vector2f(219.f, 21.f));
        rec30.setPosition(60.f, 737.f);
        rec30.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec34(sf::Vector2f(219.f, 21.f));
        rec34.setPosition(393.f, 737.f);
        rec34.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec29(sf::Vector2f(25.f, 93.f));
        rec29.setPosition(180.f, 665.f);
        rec29.setFillColor(sf::Color::Blue);
        sf::RectangleShape rec33(sf::Vector2f(25.f, 93.f));
        rec33.setPosition(467.f, 665.f);
        rec33.setFillColor(sf::Color::Blue);
        sf::RectangleShape mobspawn(sf::Vector2f(169.f, 94.f));
        mobspawn.setPosition(251.f, 376.f);
        mobspawn.setFillColor(sf::Color::Blue);
        sf::RectangleShape characcheckchon(sf::Vector2f(26.f, 36.f));
        sf::Texture redmon;
        if (!redmon.loadFromFile("image/monred1.png"))
        {
            std::cout << "Load Red Monster Failed" << std::endl;
        }
        sf::Texture pinkmon;
        if (!pinkmon.loadFromFile("image/monpink1.png"))
        {
            std::cout << "Load Pink Monster Failed" << std::endl;
        }
        sf::Texture orangemon;
        if (!orangemon.loadFromFile("image/monorange1.png"))
        {
            std::cout << "Load Orange Monster Failed" << std::endl;
        }
        sf::Sprite mon1;
        mon1.setTexture(redmon);
        int monredSizeX = redmon.getSize().x / 4;
        int monredSizeY = redmon.getSize().y / 1;
        mon1.setTextureRect(sf::IntRect(0, 0, monredSizeX, monredSizeY));
        mon1.setPosition(265.f, 400.f);
        mon1.setScale(sf::Vector2f(.21f, .2f));
        sf::Sprite mon2;
        mon2.setTexture(pinkmon);
        int monpinkSizeX = pinkmon.getSize().x / 4;
        int monpinkSizeY = pinkmon.getSize().y / 1;
        mon2.setTextureRect(sf::IntRect(0, 0, monpinkSizeX, monpinkSizeY));
        mon2.setPosition(315.f, 400.f);
        mon2.setScale(sf::Vector2f(.21f, .205f));
        sf::Sprite mon3;
        mon3.setTexture(orangemon);
        int monorangeSizeX = orangemon.getSize().x / 4;
        int monorangeSizeY = orangemon.getSize().y / 1;
        mon3.setTextureRect(sf::IntRect(0, 0, monorangeSizeX, monorangeSizeY));
        mon3.setPosition(363.f, 400.f);
        mon3.setScale(sf::Vector2f(.2f, .2f));
        int monterFrame=0;
        sf::Texture energydrink;
        if (!energydrink.loadFromFile("image/sprite.png"))
        {
            std::cout << "Load Energydrink Failed" << std::endl;
        }
        sf::Sprite Sprite[16];
        for (int i = 0; i < 16; i++)
        {
            Sprite[i].setTexture(energydrink);
            Sprite[i].setTextureRect(sf::IntRect(142, 19, 213, 461));
            Sprite[i].setScale(0.09f, 0.065f);
        }
        Sprite[0].setPosition(216.f, 659.f);
        Sprite[1].setPosition(431.f, 659.f);
        Sprite[2].setPosition(623.f, 732.f);
        Sprite[3].setPosition(25.f, 732.f);
        Sprite[4].setPosition(25.f, 586.f);
        Sprite[5].setPosition(623.f, 586.f);
        Sprite[6].setPosition(284.f, 586.f);
        Sprite[7].setPosition(360.f, 586.f);
        Sprite[8].setPosition(181.f, 406.f);
        Sprite[9].setPosition(468.f, 406.f);
        Sprite[10].setPosition(289.f, 299.f);
        Sprite[11].setPosition(362.f, 299.f);
        Sprite[12].setPosition(21.f, 226.f);
        Sprite[13].setPosition(624.f, 226.f);
        Sprite[14].setPosition(291.f, 144.f);
        Sprite[15].setPosition(362.f, 144.f);
        sf::Texture Food;
        if (!Food.loadFromFile("image/food.png"))
        {
            std::cout << "Load Food Failed" << std::endl;
        }
        sf::Sprite food[194];
        for (int i = 0; i < 194; i++)
        {
            food[i].setTexture(Food);
            food[i].setTextureRect(sf::IntRect(0,0,225,290));
            food[i].setScale(0.13f, 0.095f);
            
        }
        int j = 0;
        for (j = 0; j < 10; j++) food[j].setPosition(17.f + (30*j) , 94.f);
        for (j = 10; j < 20; j++) food[j].setPosition(352.f + (30 * (j-10)), 94.f);
        for (j = 20; j < 38; j++) food[j].setPosition(139.f,128+(34*(j-20)));
        for (j = 38; j < 56; j++) food[j].setPosition(500.f, 128.f+(34 * (j - 38)));
        for (j = 56; j < 66; j++) food[j].setPosition(15.f + (30 * (j - 56)), 771.f);
        for (j = 66; j < 76; j++) food[j].setPosition(353.f + (30 * (j - 66)), 771.f);
        for (j = 76; j < 80; j++) food[j].setPosition(17.f + (30 * (j-76)), 190.f);
        for (j = 80; j < 91; j++) food[j].setPosition(170.f + (30 * (j - 80)), 190.f);
        for (j = 91; j < 95; j++) food[j].setPosition(532.f + (30 * (j - 91)), 190.f);
        for (j = 95; j < 99; j++) food[j].setPosition(17.f + (30 * (j - 95)), 264.f);
        for (j = 99; j < 103; j++) food[j].setPosition(205.f + (30 * (j - 99)), 264.f);
        for (j = 103; j < 107; j++) food[j].setPosition(350.f + (30 * (j - 103)), 264.f);
        for (j = 107; j < 111; j++) food[j].setPosition(532.f + (30 * (j - 107)), 264.f);
        for (j = 111; j < 119; j++) food[j].setPosition(215.f + (30 * (j - 111)), 338.f);
        for (j = 119; j < 126; j++) food[j].setPosition(215.f, 373.f + (30 * (j - 119)));
        for (j = 126; j < 133; j++) food[j].setPosition(426.f, 373.f + (30 * (j - 126)));
        for (j = 133; j < 139; j++) food[j].setPosition(245.f + (30 * (j - 133)), 479.f);
        for (j = 139; j < 141; j++) food[j].setPosition(254.f + (30 * (j - 139)), 553.f);
        for (j = 141; j < 143; j++) food[j].setPosition(358.f + (30 * (j - 141)), 553.f);
        for (j = 143; j < 154; j++) food[j].setPosition(170.f + (30 * (j - 143)), 624.f);
        for (j = 154; j < 158; j++) food[j].setPosition(17.f + (30 * (j - 154)), 553.f);
        for (j = 158; j < 162; j++) food[j].setPosition(532.f + (30 * (j - 158)), 553.f);
        for (j = 162; j < 165; j++) food[j].setPosition(17.f + (30 * (j - 162)), 624.f);
        for (j = 165; j < 168; j++) food[j].setPosition(565.f + (30 * (j - 165)), 624.f);
        for (j = 168; j < 172; j++) food[j].setPosition(17.f + (30 * (j - 168)), 699.f);
        for (j = 172; j < 176; j++) food[j].setPosition(206.f + (30 * (j - 172)), 699.f);
        for (j = 176; j < 180; j++) food[j].setPosition(349.f + (30 * (j - 176)), 699.f);
        for (j = 180; j < 184; j++) food[j].setPosition(532.f + (30 * (j - 180)), 699.f);
        food[184].setPosition(17.f, 143.f);
        food[185].setPosition(622.f, 143.f);
        food[186].setPosition(211.f, 226.f);
        food[187].setPosition(427.f, 226.f);
        food[188].setPosition(284.f, 730.f);
        food[189].setPosition(359.f, 730.f);
        food[190].setPosition(65.f, 664.f);
        food[191].setPosition(577.f, 664.f);
        food[192].setPosition(175.f, 551.f);
        food[193].setPosition(466.f, 551.f);
        while (window.isOpen())
        {
            sf::Time  time = Clock.getElapsedTime();
            sf::sleep;
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            Clock.restart();

            if (menu == 0)
            {
                window.clear();
                window.draw(Logoim);
                window.draw(Startbut);
                window.draw(Contrbut);
                window.draw(exitbut);
                mission01.stop();
                window.display();
                sf::Vector2i position = sf::Mouse::getPosition(window);
                if ((position.x >= 184 && position.x <= 504) && (position.y >= 350 && position.y <= 415) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                {
                    menu = 1;
                    mission01.play();
                }
                if ((position.x >= 184 && position.x <= 504) && (position.y >= 450 && position.y <= 515) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                {
                    menu = 2;
                }
                if ((position.x >= 184 && position.x <= 504) && (position.y >= 550 && position.y <= 615) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                {
                    menu = 3;
                }
            }
            if (menu == 2)
            {
                window.clear(sf::Color(255,255,255));
                window.draw(controlimage);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) menu = 0;
                window.display();
            }
            if (menu == 3)
            {
                window.close();
            }
            if (menu == 4)
            {
                window.clear();
                window.draw(winn);
                endtime += time.asSeconds();
                if (endtime >= 3)window.close();
                window.display();
            }
            if (menu == 5)
            {
                window.clear(sf::Color(255, 255, 255));
                window.draw(loser);
                endtime += time.asSeconds();
                if (endtime >= 3)window.close();
                window.display();
            }
            if (menu == 1) {
                window.draw(mobspawn);
                window.draw(rec1); window.draw(rec2); window.draw(rec4); window.draw(rec3); window.draw(rec5); window.draw(rec6); window.draw(rec7); window.draw(rec8);
                window.draw(rec11); window.draw(rec13); window.draw(rec9); window.draw(rec10); window.draw(rec12); window.draw(rec14); window.draw(rec15);
                window.draw(rec16); window.draw(rec21); window.draw(rec17); window.draw(rec20); window.draw(rec18);
                window.draw(rec22); window.draw(rec24); window.draw(rec25); window.draw(rec27); window.draw(rec19); window.draw(rec23); window.draw(rec26); window.draw(rec28); window.draw(rec35); window.draw(rec31);
                window.draw(rec32); window.draw(rec30); window.draw(rec34); window.draw(rec29); window.draw(rec33);
                characcheckchon.setPosition(shapeSprite.getPosition().x, shapeSprite.getPosition().y);
                window.draw(MapSprite); 
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) menu = 0;
                if (warpcooldown < 5)
                {
                    leftportal.setPosition(-100.f, 400.f);
                    rightportal.setPosition(800.f, 400.f);
                    closeleftportal.setPosition(-10.f, 400.f);
                    closerightportal.setPosition(630.f, 400.f);
                }
                else
                {
                    leftportal.setPosition(0.f, 400.f);
                    rightportal.setPosition(630.f, 400.f);
                    closeleftportal.setPosition(-100.f, 400.f);
                    closerightportal.setPosition(800.f, 400.f);
                }

                window.draw(leftportal);
                window.draw(rightportal);
                window.draw(closerightportal);
                window.draw(closeleftportal);
                window.draw(credit);
                for (int j = 0; j < 194; j++)
                {
                    window.draw(food[j]);
                }
                for (int k = 0; k < 16; k++)
                {
                    window.draw(Sprite[k]);
                }
                window.draw(mon1); window.draw(mon2); window.draw(mon3);
                window.draw(shapeSprite);
                window.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    shapeSprite.move(time.asSeconds() * (100.f + itemspeed), 0.f);
                    shapeSprite.setTextureRect(sf::IntRect(65 + (19 * animationFrame), 56, 19, 27));
                    time1 += 0.001;
                    if (time1 > 0.35)
                    {
                        animationFrame++;
                        if (animationFrame >= 2)
                        {
                            animationFrame = 0;
                        }
                        time1 = 0;
                    }
                    if (rec1.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec2.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec3.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec4.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec5.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec6.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec7.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec8.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec9.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec10.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec11.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec12.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec13.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec14.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec15.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec16.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec17.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec18.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec19.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec20.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec21.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec22.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec23.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec24.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec25.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec26.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec27.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec28.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec29.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec30.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec31.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec32.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec33.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec34.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec35.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (mobspawn.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(-shapeSprite.getGlobalBounds().width * 0.35f, 0.f);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    shapeSprite.move(-time.asSeconds() * (100.f + itemspeed), 0.f);
                    shapeSprite.setTextureRect(sf::IntRect(65 + (19 * animationFrame), 87, 19, 27));
                    time1 += 0.001;
                    if (time1 > 0.35)
                    {
                        animationFrame++;
                        if (animationFrame >= 2)
                        {
                            animationFrame = 0;
                        }
                        time1 = 0;

                    }
                    if (rec1.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec2.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec3.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec4.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec5.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec6.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec7.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec8.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec9.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec10.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec11.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec12.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec13.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec14.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec15.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec16.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec17.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec18.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec19.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec20.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec21.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec22.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec23.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec24.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec25.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec26.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec27.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec28.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec29.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec30.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec31.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec32.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec33.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec34.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (rec35.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);
                    if (mobspawn.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(shapeSprite.getGlobalBounds().width * 0.35f, 0.f);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    shapeSprite.move(0.f, -time.asSeconds() * (100.f + itemspeed));
                    shapeSprite.setTextureRect(sf::IntRect(65 + (19 * animationFrame), 29, 19, 27));
                    time1 += 0.001;
                    if (time1 > 0.35)
                    {
                        animationFrame++;
                        if (animationFrame >= 2)
                        {
                            animationFrame = 0;
                        }
                        time1 = 0;

                    }
                    if (rec1.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec2.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec3.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec4.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec5.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec6.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec7.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec8.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec9.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec10.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec11.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec12.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec13.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec14.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec15.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec16.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec17.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec18.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec19.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec20.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec21.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec22.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec23.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec24.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec25.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec26.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec27.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec28.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec29.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec30.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec31.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec32.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec33.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec34.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec35.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);
                    if (mobspawn.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, shapeSprite.getGlobalBounds().height * 0.35f);

                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    shapeSprite.move(0.f, time.asSeconds() * (100.f + itemspeed));
                    shapeSprite.setTextureRect(sf::IntRect(65 + (19 * animationFrame), 2, 19, 27));
                    time1 += 0.001;
                    if (time1 > 0.35)
                    {
                        animationFrame++;
                        if (animationFrame >= 2)
                        {
                            animationFrame = 0;
                        }
                        time1 = 0;
                    }
                    if (rec1.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec2.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec3.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec4.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec5.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec6.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec7.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec8.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec9.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec10.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec11.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec12.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec13.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec14.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec15.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec16.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec17.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec18.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec19.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec20.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec21.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec22.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec23.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec24.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec25.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec26.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec27.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec28.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec29.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec30.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec31.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec32.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec33.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec34.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (rec35.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);
                    if (mobspawn.getGlobalBounds().intersects(characcheckchon.getGlobalBounds())) shapeSprite.move(0.f, -shapeSprite.getGlobalBounds().height * 0.35f);

                }
                //LEFT collision
                if (shapeSprite.getPosition().x < 12.f)
                    shapeSprite.setPosition(12.f, shapeSprite.getPosition().y);
                //TOP collision
                if (shapeSprite.getPosition().y < 86.f)
                    shapeSprite.setPosition(shapeSprite.getPosition().x, 86.f);
                //RIGHT collision
                if (shapeSprite.getPosition().x + shapeSprite.getGlobalBounds().width > 660.f)
                    shapeSprite.setPosition(660.f - shapeSprite.getGlobalBounds().width, shapeSprite.getPosition().y);
                //BOTTOM collision
                if (shapeSprite.getPosition().y + shapeSprite.getGlobalBounds().height > 808.f)
                    shapeSprite.setPosition(shapeSprite.getPosition().x, 808.f - shapeSprite.getGlobalBounds().height);
                if (leftportal.getGlobalBounds().intersects(shapeSprite.getGlobalBounds()) && warpcooldown > 5)
                {
                    shapeSprite.setPosition(600.f, 405.f);
                    warpcooldown = 0;
                }
                if (rightportal.getGlobalBounds().intersects(shapeSprite.getGlobalBounds()) && warpcooldown > 5)
                {
                    shapeSprite.setPosition(50.f, 405.f);
                    warpcooldown = 0;
                }
                timemon += 0.0003;
                if (timemon > 0.3)
                {
                    monterFrame++;
                    if (monterFrame >= 4)
                    {
                        monterFrame = 0;
                    }
                    timemon = 0;
                }
                mon1.setTextureRect(sf::IntRect(monredSizeX * monterFrame, 0, monredSizeX, monredSizeY));
                mon2.setTextureRect(sf::IntRect(monpinkSizeX * monterFrame, 0, monpinkSizeX, monpinkSizeY));
                mon3.setTextureRect(sf::IntRect(monorangeSizeX * monterFrame, 0, monorangeSizeX, monorangeSizeY));
                warpcooldown += time.asSeconds();
                for (j = 0; j < 194; j++)
                {
                    if (food[j].getGlobalBounds().intersects(shapeSprite.getGlobalBounds()))
                    {
                        food[j].setPosition(-100.f, -100.f);
                        score++;
                    }
                }
                for (int k = 0; k < 16; k++)
                {
                    if (Sprite[k].getGlobalBounds().intersects(shapeSprite.getGlobalBounds()))
                    {
                        Sprite[k].setPosition(-100.f, -100.f);
                        itemspeedtime = 2;
                    }
                }
                itemspeedtime -= time.asSeconds();
                if (itemspeedtime > 0)
                {
                    itemspeed = 75;
                }
                else itemspeed = 0;
                timemonrun += time.asSeconds();
                
                //mon2
                if (timemonrun >= 3 && timemonrun < 3.5)m2p = -1;
                if (m2p == -1) mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == -1 && mon2.getPosition().y > 332.f && mon2.getPosition().y < 335)m2p = 0;
                if (m2p == 0 && shapeSprite.getPosition().x > 324.f) m2p = 11;
                if (m2p == 0 && shapeSprite.getPosition().x < 324.f) m2p = 12;
                if (m2p == 11)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 11 && (mon2.getPosition().x > 417.f && mon2.getPosition().x < 422.f)) m2p = 21;//ขวา
                if (m2p == 12)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 12 && (mon2.getPosition().x > 204.f && mon2.getPosition().x < 207.f)) m2p = 22;//ซ้าย
                if (m2p == 21 || m2p == 22) mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 21 && mon2.getPosition().y > 400.f && mon2.getPosition().y < 406.f)m2p = 31;
                if (m2p == 31) mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 31 && mon2.getPosition().y < 548 && mon2.getPosition().y>543)m2p = 41;
                if (m2p == 41)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 41 && mon2.getPosition().x > 492.f && mon2.getPosition().x < 495.f)m2p = 61;
                if (m2p == 61 && shapeSprite.getPosition().y > mon2.getPosition().y)m2p = 612;
                if (m2p == 612)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 612 && mon2.getPosition().y > 689 && mon2.getPosition().y < 692)m2p = 151;
                if (m2p == 151)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 151 && mon2.getPosition().x > 615 && mon2.getPosition().x < 617)m2p = 161;
                if (m2p == 161)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 161 && mon2.getPosition().y > 764 && mon2.getPosition().y < 766)m2p = 171;
                if (m2p == 171)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 171 && mon2.getPosition().x > 349 && mon2.getPosition().x < 351)m2p = 181;
                if (m2p == 181)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 181 && mon2.getPosition().y > 694 && mon2.getPosition().y < 697)m2p = 191;
                if (m2p == 191)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 191 && mon2.getPosition().x > 419 && mon2.getPosition().x < 421)m2p = 201;
                if (m2p == 201)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 201 && mon2.getPosition().y > 618 && mon2.getPosition().y < 620)m2p = 211;
                if (m2p == 211)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 211 && mon2.getPosition().x > 347 && mon2.getPosition().x < 349)m2p = 221;
                if (m2p == 221)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 221 && mon2.getPosition().y > 545 && mon2.getPosition().y < 547)m2p = 231;
                if (m2p == 231)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 231 && mon2.getPosition().x > 417.f && mon2.getPosition().x < 422.f)m2p = 41;
                if (m2p == 61 && shapeSprite.getPosition().y < mon2.getPosition().y)m2p = 611;
                if (m2p == 611)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 611 && mon2.getPosition().y > 188 && mon2.getPosition().y < 193)m2p = 81;
                if (m2p == 81)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 81 && mon2.getPosition().x > 208 && mon2.getPosition().x < 211)m2p = 92;
                if (m2p == 92)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 92 && mon2.getPosition().y > 257 && mon2.getPosition().y < 261)m2p = 102;
                if (m2p == 102)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 102 && mon2.getPosition().x > 277 && mon2.getPosition().x < 281)m2p = 112;
                if (m2p == 112)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 112 && mon2.getPosition().y > 332 && mon2.getPosition().y < 335)m2p = 122;
                if (m2p == 122 && mon2.getPosition().x > shapeSprite.getPosition().x)m2p = 1221;
                if (m2p == 1221)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 1221 && mon2.getPosition().x > 200.f && mon2.getPosition().x < 205.f) m2p = 22;
                if (m2p == 122 && mon2.getPosition().x < shapeSprite.getPosition().x)m2p = 1222;
                if (m2p == 1222)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 1222 && mon2.getPosition().x > 417.f && mon2.getPosition().x < 422.f) m2p = 21;
                if (m2p == 22 && mon2.getPosition().y > 402.f && mon2.getPosition().y < 406.f)m2p = 32;
                if (m2p == 32) mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 32 && mon2.getPosition().y < 547 && mon2.getPosition().y>544)m2p = 42;
                if (m2p == 42)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 42 && mon2.getPosition().x > 134.f && mon2.getPosition().x < 136.f)m2p = 62;
                if (m2p == 62 && shapeSprite.getPosition().y > mon2.getPosition().y)m2p = 622;
                if (m2p == 622)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 622 && mon2.getPosition().y > 689 && mon2.getPosition().y < 692)m2p = 152;
                if (m2p == 152)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 152 && mon2.getPosition().x > 15 && mon2.getPosition().x < 17)m2p = 162;
                if (m2p == 162)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 162 && mon2.getPosition().y > 764 && mon2.getPosition().y < 766)m2p = 172;
                if (m2p == 172)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 172 && mon2.getPosition().x > 278 && mon2.getPosition().x < 281)m2p = 182;
                if (m2p == 182)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 182 && mon2.getPosition().y > 694 && mon2.getPosition().y < 697)m2p = 192;
                if (m2p == 192)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 192 && mon2.getPosition().x > 203 && mon2.getPosition().x < 205)m2p = 202;
                if (m2p == 202)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 202 && mon2.getPosition().y > 618 && mon2.getPosition().y < 620)m2p = 212;
                if (m2p == 212)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 212 && mon2.getPosition().x > 277 && mon2.getPosition().x < 279)m2p = 222;
                if (m2p == 222)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 222 && mon2.getPosition().y > 545 && mon2.getPosition().y < 547)m2p = 232;
                if (m2p == 232)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 232 && mon2.getPosition().x > 208.f && mon2.getPosition().x < 211.f)m2p = 42;
                if (m2p == 62 && shapeSprite.getPosition().y < mon2.getPosition().y)m2p = 621;
                if (m2p == 621)mon2.move(0.f, -time.asSeconds() * 100.f);
                if (m2p == 621 && mon2.getPosition().y > 188 && mon2.getPosition().y < 193)m2p = 82;
                if (m2p == 82)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 82 && mon2.getPosition().x > 420 && mon2.getPosition().x < 424)m2p = 91;
                if (m2p == 91)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 91 && mon2.getPosition().y > 257 && mon2.getPosition().y < 261)m2p = 101;
                if (m2p == 101)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 101 && mon2.getPosition().x > 344 && mon2.getPosition().x < 348)m2p = 111;
                if (m2p == 111)mon2.move(0.f, time.asSeconds() * 100.f);
                if (m2p == 111 && mon2.getPosition().y > 332 && mon2.getPosition().y < 335)m2p = 121;
                if (m2p == 121 && mon2.getPosition().x > shapeSprite.getPosition().x)m2p = 1211;
                if (m2p == 1211)mon2.move(-time.asSeconds() * 100.f, 0.f);
                if (m2p == 1211 && mon2.getPosition().x > 204.f && mon2.getPosition().x < 207.f) m2p = 22;
                if (m2p == 121 && mon2.getPosition().x < shapeSprite.getPosition().x)m2p = 1212;
                if (m2p == 1212)mon2.move(time.asSeconds() * 100.f, 0.f);
                if (m2p == 1212 && mon2.getPosition().x > 417.f && mon2.getPosition().x < 422.f) m2p = 21;
                //mon1
                if (timemonrun > 4.5 && timemonrun < 5)m1p = -2;
                if (m1p == -2)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == -2 && mon1.getPosition().x > 315 && mon1.getPosition().x < 320)m1p = -1;
                if (m1p == -1)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == -1 && mon1.getPosition().y > 332.f && mon1.getPosition().y < 335)m1p = 0;
                if (m1p == 0 && shapeSprite.getPosition().x > 324.f) m1p = 12;
                if (m1p == 0 && shapeSprite.getPosition().x < 324.f) m1p = 11;
                if (m1p == 11)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 11 && (mon1.getPosition().x > 417.f && mon1.getPosition().x < 422.f)) m1p = 21;//ขวา
                if (m1p == 12)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 12 && (mon1.getPosition().x > 204.f && mon1.getPosition().x < 207.f)) m1p = 22;//ซ้าย
                if (m1p == 21 || m1p == 22) mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 21 && mon1.getPosition().y > 400.f && mon1.getPosition().y < 406.f)m1p = 31;
                if (m1p == 31) mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 31 && mon1.getPosition().y < 548 && mon1.getPosition().y>543)m1p = 41;
                if (m1p == 41)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 41 && mon1.getPosition().x > 492.f && mon1.getPosition().x < 495.f)m1p = 61;
                if (m1p == 61 && shapeSprite.getPosition().y > mon1.getPosition().y)m1p = 612;
                if (m1p == 612)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 612 && mon1.getPosition().y > 689 && mon1.getPosition().y < 692)m1p = 151;
                if (m1p == 151)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 151 && mon1.getPosition().x > 615 && mon1.getPosition().x < 617)m1p = 161;
                if (m1p == 161)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 161 && mon1.getPosition().y > 764 && mon1.getPosition().y < 766)m1p = 171;
                if (m1p == 171)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 171 && mon1.getPosition().x > 349 && mon1.getPosition().x < 351)m1p = 181;
                if (m1p == 181)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 181 && mon1.getPosition().y > 694 && mon1.getPosition().y < 697)m1p = 191;
                if (m1p == 191)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 191 && mon1.getPosition().x > 419 && mon1.getPosition().x < 421)m1p = 201;
                if (m1p == 201)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 201 && mon1.getPosition().y > 618 && mon1.getPosition().y < 620)m1p = 211;
                if (m1p == 211)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 211 && mon1.getPosition().x > 347 && mon1.getPosition().x < 349)m1p = 221;
                if (m1p == 221)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 221 && mon1.getPosition().y > 545 && mon1.getPosition().y < 547)m1p = 231;
                if (m1p == 231)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 231 && mon1.getPosition().x > 417.f && mon1.getPosition().x < 422.f)m1p = 41;
                if (m1p == 61 && shapeSprite.getPosition().y < mon1.getPosition().y)m1p = 611;
                if (m1p == 611)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 611 && mon1.getPosition().y > 188 && mon1.getPosition().y < 193)m1p = 81;
                if (m1p == 81)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 81 && mon1.getPosition().x > 208 && mon1.getPosition().x < 211)m1p = 92;
                if (m1p == 92)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 92 && mon1.getPosition().y > 257 && mon1.getPosition().y < 261)m1p = 102;
                if (m1p == 102)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 102 && mon1.getPosition().x > 277 && mon1.getPosition().x < 281)m1p = 112;
                if (m1p == 112)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 112 && mon1.getPosition().y > 332 && mon1.getPosition().y < 335)m1p = 122;
                if (m1p == 122 && mon1.getPosition().x > shapeSprite.getPosition().x)m1p = 1221;
                if (m1p == 1221)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 1221 && mon1.getPosition().x > 200.f && mon1.getPosition().x < 205.f) m1p = 22;
                if (m1p == 122 && mon1.getPosition().x < shapeSprite.getPosition().x)m1p = 1222;
                if (m1p == 1222)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 1222 && mon1.getPosition().x > 417.f && mon1.getPosition().x < 422.f) m1p = 21;
                if (m1p == 22 && mon1.getPosition().y > 402.f && mon1.getPosition().y < 406.f)m1p = 32;
                if (m1p == 32) mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 32 && mon1.getPosition().y < 547 && mon1.getPosition().y>544)m1p = 42;
                if (m1p == 42)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 42 && mon1.getPosition().x > 134.f && mon1.getPosition().x < 136.f)m1p = 62;
                if (m1p == 62 && shapeSprite.getPosition().y > mon1.getPosition().y)m1p = 622;
                if (m1p == 622)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 622 && mon1.getPosition().y > 689 && mon1.getPosition().y < 692)m1p = 152;
                if (m1p == 152)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 152 && mon1.getPosition().x > 15 && mon1.getPosition().x < 17)m1p = 162;
                if (m1p == 162)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 162 && mon1.getPosition().y > 764 && mon1.getPosition().y < 766)m1p = 172;
                if (m1p == 172)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 172 && mon1.getPosition().x > 278 && mon1.getPosition().x < 281)m1p = 182;
                if (m1p == 182)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 182 && mon1.getPosition().y > 694 && mon1.getPosition().y < 697)m1p = 192;
                if (m1p == 192)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 192 && mon1.getPosition().x > 203 && mon1.getPosition().x < 205)m1p = 202;
                if (m1p == 202)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 202 && mon1.getPosition().y > 618 && mon1.getPosition().y < 620)m1p = 212;
                if (m1p == 212)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 212 && mon1.getPosition().x > 277 && mon1.getPosition().x < 279)m1p = 222;
                if (m1p == 222)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 222 && mon1.getPosition().y > 545 && mon1.getPosition().y < 547)m1p = 232;
                if (m1p == 232)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 232 && mon1.getPosition().x > 208.f && mon1.getPosition().x < 211.f)m1p = 42;
                if (m1p == 62 && shapeSprite.getPosition().y < mon1.getPosition().y)m1p = 621;
                if (m1p == 621)mon1.move(0.f, -time.asSeconds() * 100.f);
                if (m1p == 621 && mon1.getPosition().y > 188 && mon1.getPosition().y < 193)m1p = 82;
                if (m1p == 82)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 82 && mon1.getPosition().x > 420 && mon1.getPosition().x < 424)m1p = 91;
                if (m1p == 91)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 91 && mon1.getPosition().y > 257 && mon1.getPosition().y < 261)m1p = 101;
                if (m1p == 101)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 101 && mon1.getPosition().x > 344 && mon1.getPosition().x < 348)m1p = 111;
                if (m1p == 111)mon1.move(0.f, time.asSeconds() * 100.f);
                if (m1p == 111 && mon1.getPosition().y > 332 && mon1.getPosition().y < 335)m1p = 121;
                if (m1p == 121 && mon1.getPosition().x > shapeSprite.getPosition().x)m1p = 1211;
                if (m1p == 1211)mon1.move(-time.asSeconds() * 100.f, 0.f);
                if (m1p == 1211 && mon1.getPosition().x > 204.f && mon1.getPosition().x < 207.f) m1p = 22;
                if (m1p == 121 && mon1.getPosition().x < shapeSprite.getPosition().x)m1p = 1212;
                if (m1p == 1212)mon1.move(time.asSeconds() * 100.f, 0.f);
                if (m1p == 1212 && mon1.getPosition().x > 417.f && mon1.getPosition().x < 422.f) m1p = 21;

                //mon3

                if (timemonrun > 3.5 && timemonrun < 3.7)m3p = -2;
                if (m3p == -2)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == -2 && mon3.getPosition().x > 315 && mon3.getPosition().x < 320)m3p = -1;
                if (m3p == -1)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == -1 && mon3.getPosition().y > 332.f && mon3.getPosition().y < 335)m3p = 0;
                if (m3p == 0 && shapeSprite.getPosition().x > 324.f) m3p = 12;
                if (m3p == 0 && shapeSprite.getPosition().x < 324.f) m3p = 11;
                if (m3p == 11)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 11 && (mon3.getPosition().x > 417.f && mon3.getPosition().x < 422.f)) m3p = 21;//ขวา
                if (m3p == 12)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 12 && (mon3.getPosition().x > 204.f && mon3.getPosition().x < 207.f)) m3p = 22;//ซ้าย
                if (m3p == 21 || m3p == 22) mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 21 && mon3.getPosition().y > 400.f && mon3.getPosition().y < 406.f)m3p = 31;
                if (m3p == 31) mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 31 && mon3.getPosition().y < 548 && mon3.getPosition().y>543)m3p = 41;
                if (m3p == 41)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 41 && mon3.getPosition().x > 492.f && mon3.getPosition().x < 495.f)m3p = 61;
                if (m3p == 61 && shapeSprite.getPosition().y > mon3.getPosition().y)m3p = 612;
                if (m3p == 61 && shapeSprite.getPosition().y < mon3.getPosition().y)m3p = 611;
                if (m3p == 612)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 612 && mon3.getPosition().y > 618 && mon3.getPosition().y < 620)m3p = 161;
                if (m3p == 161)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 161 && mon3.getPosition().x > 133 && mon3.getPosition().x < 135)m3p = 1621;
                if (m3p == 22 && mon3.getPosition().y > 402.f && mon3.getPosition().y < 406.f)m3p = 32;
                if (m3p == 32) mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 32 && mon3.getPosition().y < 547 && mon3.getPosition().y>544)m3p = 42;
                if (m3p == 42)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 42 && mon3.getPosition().x > 134.f && mon3.getPosition().x < 136.f)m3p = 62;
                if (m3p == 62 && shapeSprite.getPosition().y > mon3.getPosition().y)m3p = 622;
                if (m3p == 62 && shapeSprite.getPosition().y < mon3.getPosition().y)m3p = 621;
                if (m3p == 622)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 622 && mon3.getPosition().y > 618 && mon3.getPosition().y < 620)m3p = 162;
                if (m3p == 162)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 162 && mon3.getPosition().x > 496 && mon3.getPosition().x < 498)m3p = 1622;
                if (m3p == 1621 || m3p == 1622)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 1621 && mon3.getPosition().y > 694 && mon3.getPosition().y < 696)m3p = 172;
                if (m3p == 172)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 172 && mon3.getPosition().x > 63 && mon3.getPosition().x < 65)m3p = 182;
                if (m3p == 182)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 182 && mon3.getPosition().y > 617 && mon3.getPosition().y < 619)m3p = 192;
                if (m3p == 192)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 192 && mon3.getPosition().x > 17 && mon3.getPosition().x < 20)m3p = 202;
                if (m3p == 202)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 202 && mon3.getPosition().y > 550 && mon3.getPosition().y < 552)m3p = 212;
                if (m3p == 212)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 212 && mon3.getPosition().x > 134.f && mon3.getPosition().x < 136.f)m3p = 62;
                if (m3p == 1622 && mon3.getPosition().y > 694 && mon3.getPosition().y < 696)m3p = 171;
                if (m3p == 171)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 171 && mon3.getPosition().x > 570 && mon3.getPosition().x < 572)m3p = 181;
                if (m3p == 181)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 181 && mon3.getPosition().y > 617 && mon3.getPosition().y < 619)m3p = 191;
                if (m3p == 191)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 191 && mon3.getPosition().x > 612 && mon3.getPosition().x < 614)m3p = 201;
                if (m3p == 201)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 201 && mon3.getPosition().y > 550 && mon3.getPosition().y < 552)m3p = 211;
                if (m3p == 211)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 211 && mon3.getPosition().x > 494.f && mon3.getPosition().x < 497.f)m3p = 61;
                if (m3p == 611 || m3p == 621)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 621 && mon3.getPosition().y > 259 && mon3.getPosition().y < 261)m3p = 302;
                if (m3p == 302)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 302 && mon3.getPosition().x > 16 && mon3.getPosition().x < 18)m3p = 312;
                if (m3p == 312)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 312 && mon3.getPosition().y > 93 && mon3.getPosition().y < 96)m3p = 322;
                if (m3p == 322)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 322 && mon3.getPosition().x > 279 && mon3.getPosition().x < 281)m3p = 332;
                if (m3p == 332)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 332 && mon3.getPosition().y > 184 && mon3.getPosition().y < 187)m3p = 342;
                if (m3p == 342)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 342 && mon3.getPosition().x > 352 && mon3.getPosition().x < 355)m3p = 352;
                if (m3p == 352)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 352 && mon3.getPosition().y > 93 && mon3.getPosition().y < 96)m3p = 362;
                if (m3p == 362)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 362 && mon3.getPosition().x > 614 && mon3.getPosition().x < 616)m3p = 372;
                if (m3p == 372)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 372 && mon3.getPosition().y > 260 && mon3.getPosition().y < 262)m3p = 382;
                if (m3p == 382)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 382 && mon3.getPosition().x > 496 && mon3.getPosition().x < 498)m3p = 392;
                if (m3p == 392)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 392 && mon3.getPosition().y > 401 && mon3.getPosition().y < 403)m3p = 402;
                if (m3p == 402)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 402 && mon3.getPosition().x > 417.f && mon3.getPosition().x < 422.f)m3p = 31;
                if (m3p == 611 && mon3.getPosition().y > 259 && mon3.getPosition().y < 261)m3p = 301;
                if (m3p == 301)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 301 && mon3.getPosition().x > 614 && mon3.getPosition().x > 616)m3p = 311;
                if (m3p == 311)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 311 && mon3.getPosition().y > 93 && mon3.getPosition().y < 95)m3p = 321;
                if (m3p == 321)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 321 && mon3.getPosition().x > 352 && mon3.getPosition().x < 354)m3p = 331;
                if (m3p == 331)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 331 && mon3.getPosition().y > 185 && mon3.getPosition().y < 187)m3p = 341;
                if (m3p == 341)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 341 && mon3.getPosition().x > 278 && mon3.getPosition().x < 281)m3p = 351;
                if (m3p == 351)mon3.move(0.f, -time.asSeconds() * 100.f);
                if (m3p == 351 && mon3.getPosition().y > 93 && mon3.getPosition().y < 95)m3p = 361;
                if (m3p == 361)mon3.move(-time.asSeconds() * 100.f, 0.f);
                if (m3p == 361 && mon3.getPosition().x > 16 && mon3.getPosition().x < 18)m3p = 371;
                if (m3p == 371)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 371 && mon3.getPosition().y > 259 && mon3.getPosition().y < 261)m3p = 381;
                if (m3p == 381)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 381 && mon3.getPosition().x > 132 && mon3.getPosition().x < 134)m3p = 391;
                if (m3p == 391)mon3.move(0.f, time.asSeconds() * 100.f);
                if (m3p == 391 && mon3.getPosition().y > 401 && mon3.getPosition().y < 403)m3p = 401;
                if (m3p == 401)mon3.move(time.asSeconds() * 100.f, 0.f);
                if (m3p == 401 && mon3.getPosition().x > 204.f && mon3.getPosition().x < 207.f)m3p = 32;
                if (shapeSprite.getGlobalBounds().intersects(mon1.getGlobalBounds()) || shapeSprite.getGlobalBounds().intersects(mon2.getGlobalBounds()) || shapeSprite.getGlobalBounds().intersects(mon3.getGlobalBounds()))
                {
                    mission01.stop();
                    menu = 5;
                }
                if (score >= 194) menu = 4;
                if (menu == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) menu = 4;
                if (menu == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) menu = 5;
                
            }
        }
   return 0;
}
