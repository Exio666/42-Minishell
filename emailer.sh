git filter-branch --commit-filter '
              GIT_AUTHOR_NAME="Benoit Savinel";
              GIT_AUTHOR_EMAIL="bsavinel@student.42.fr";
              git commit-tree "$@";'