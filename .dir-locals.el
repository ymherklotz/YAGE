((nil . ((eval . (progn
                   (require 'projectile)
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "include")))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "googletest/googletest/include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "googletest/googletest/include"))))))))))
