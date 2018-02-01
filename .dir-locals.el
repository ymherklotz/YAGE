((nil . ((projectile-project-compilation-cmd . "mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && make -j4")
         (projectile-project-test-cmd . "cd build/tests && ctest")
         (projectile-project-run-cmd . "./build/bin/simplegame"))))
