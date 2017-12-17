((nil . ((projectile-project-compilation-cmd . "mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DUNIT_TESTS=ON .. && make -j9")
         (projectile-project-test-cmd . "cd build && ctest")
         (projectile-project-run-cmd . "./bin/simplegame"))))
