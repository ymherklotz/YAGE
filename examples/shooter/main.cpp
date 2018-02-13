#include <yage/yage.h>

#include "bullet.h"
#include "direction.h"
#include "player.h"

#include <memory>
#include <vector>

using std::cout;

int main(int argc, char **argv)
{
    yage::init();
    yage::Window window;
    window.create("Shooter example", 800, 600);

    std::vector<std::unique_ptr<Bullet>> bullets;

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

        if (window.keyPressed(yage::key::RIGHT)) {
            bullets.push_back(std::make_unique<Bullet>(
                glm::vec4(player.position().x + player.position().z / 2.f,
                          player.position().y + player.position().w / 2.f, 25,
                          25),
                Direction::RIGHT, 10.f));
            player.look(Direction::RIGHT);
        } else if (window.keyPressed(yage::key::DOWN)) {
            bullets.push_back(std::make_unique<Bullet>(
                glm::vec4(player.position().x + player.position().z / 2.f,
                          player.position().y + player.position().w / 2.f, 25,
                          25),
                Direction::DOWN, 10.f, 2));
            player.look(Direction::DOWN);
        } else if (window.keyPressed(yage::key::LEFT)) {
            bullets.push_back(std::make_unique<Bullet>(
                glm::vec4(player.position().x + player.position().z / 2.f,
                          player.position().y + player.position().w / 2.f, 25,
                          25),
                Direction::LEFT, 10.f, 2));
            player.look(Direction::LEFT);
        } else if (window.keyPressed(yage::key::UP)) {
            bullets.push_back(std::make_unique<Bullet>(
                glm::vec4(player.position().x + player.position().z / 2.f,
                          player.position().y + player.position().w / 2.f, 25,
                          25),
                Direction::UP, 10.f));
            player.look(Direction::UP);
        }

        player.setTexture(textures[i]);

        camera.update(shader);

        window.clearBuffer();
        player.draw(sp);

        for (auto &&bullet : bullets) {
            bullet->draw(sp);
        }

        sp.render();

        window.swapBuffer();
    }
    yage::quit();
}
