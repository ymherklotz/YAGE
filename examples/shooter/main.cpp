#include <yage/yage.h>

#include "player.h"

using std::cout;

int main(int argc, char **argv)
{
    yage::Window window;
    window.create("Shooter example", 800, 600);

    yage::Shader shader("examples/resources/textureshader.vert",
                        "examples/resources/textureshader.frag");

    std::vector<yage::Texture> male_l = {
        yage::ResourceManager::getTexture("examples/resources/fighter_ml.png",
                                          3, 4),
        yage::ResourceManager::getTexture("examples/resources/ranger_ml.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/mage_ml.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/healer_ml.png", 3,
                                          4)};
    std::vector<yage::Texture> female_l = {
        yage::ResourceManager::getTexture("examples/resources/fighter_fl.png",
                                          3, 4),
        yage::ResourceManager::getTexture("examples/resources/ranger_fl.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/mage_fl.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/healer_fl.png", 3,
                                          4)};
    std::vector<yage::Texture> male_d = {
        yage::ResourceManager::getTexture("examples/resources/fighter_md.png",
                                          3, 4),
        yage::ResourceManager::getTexture("examples/resources/ranger_md.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/mage_md.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/healer_md.png", 3,
                                          4)};
    std::vector<yage::Texture> female_d = {
        yage::ResourceManager::getTexture("examples/resources/fighter_fd.png",
                                          3, 4),
        yage::ResourceManager::getTexture("examples/resources/ranger_fd.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/mage_fd.png", 3,
                                          4),
        yage::ResourceManager::getTexture("examples/resources/healer_fd.png", 3,
                                          4)};

    yage::SpriteBatch sp;
    yage::Camera camera(800, 600);

    int i              = 0;
    int j              = 0;
    bool space_pressed = false;
    bool c_pressed     = false;

    shader.use();
    shader.setUniform("texture_sampler", 0);

    auto textures = male_l;

    Player player({400, 300, 48 * 2, 64 * 2}, textures.front());

    while (!window.shouldClose()) {
        window.pollEvents();

        if (window.keyPressed(yage::key::D)) {
            player.move(Direction::RIGHT);
        }
        if (window.keyPressed(yage::key::S)) {
            player.move(Direction::DOWN);
        }
        if (window.keyPressed(yage::key::A)) {
            player.move(Direction::LEFT);
        }
        if (window.keyPressed(yage::key::W)) {
            player.move(Direction::UP);
        }
        if (!window.keyPressed(yage::key::D) &&
            !window.keyPressed(yage::key::S) &&
            !window.keyPressed(yage::key::A) &&
            !window.keyPressed(yage::key::W)) {
            player.idle();
        }
        if (window.keyPressed(yage::key::SPACE) && !space_pressed) {
            space_pressed = true;
            i             = (i + 1) % textures.size();
        }
        if (!window.keyPressed(yage::key::SPACE)) {
            space_pressed = false;
        }
        if (window.keyPressed(yage::key::C) && !c_pressed) {
            c_pressed = true;
            j         = (j + 1) % 4;
            switch (j) {
            case 0:
                textures = male_l;
                break;
            case 1:
                textures = male_d;
                break;
            case 2:
                textures = female_l;
                break;
            case 3:
                textures = female_d;
                break;
            }
        }
        if (!window.keyPressed(yage::key::C)) {
            c_pressed = false;
        }

        player.setTexture(textures[i]);

        camera.update(shader);

        window.clearBuffer();
        player.draw(sp);
        sp.render();

        window.swapBuffer();
    }
}
