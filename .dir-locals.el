((nil . ((projectile-project-compilation-cmd . "mkdir -p build && cd build && cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && ninja -j4")
         (projectile-project-test-cmd . "cd build/tests && ctest -j4 --schedule-random")
         (projectile-project-run-cmd . "./build/bin/simplegame"))))
