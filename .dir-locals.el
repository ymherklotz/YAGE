((nil . ((eval . (progn
                   (require 'projectile)
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "yage")))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root))))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "lib/googletest/googletest/include")))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "lib/rapidjson/include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "yage")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root))))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "lib/googletest/googletest/include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "lib/rapidjson/include"))))))))))
