((nil . ((projectile-project-compilation-cmd . "mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DYAGE_BUILD_TESTS=ON .. && make -j9")
         (projectile-project-test-cmd . "cd build/tests && ctest")
         (projectile-project-run-cmd . "./build/bin/simplegame"))))
