((nil . ((eval . (progn
                   (require 'projectile)
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "include")))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "lib/googletest/googletest/include")))))
                   (setq company-clang-arguments (delete-dups (append
                                                               company-clang-arguments
                                                               (list (concat "-I" (projectile-project-root) "lib/yajl/include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "lib/googletest/googletest/include")))))
                   (setq flycheck-clang-include-path (delete-dups (append
                                                                   flycheck-clang-include-path
                                                                   (list (concat (projectile-project-root) "lib/yajl/include"))))))))))
