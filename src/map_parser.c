#include "../includes/so_long.h"
#include "../libft/libft/libft.h"
#include "../libft/get_next_line/get_next_line.h"

void exit_with_error(char *message) {
    printf("Error\n%s\n", message);
    exit(1);
}

void parse_map(char *file, t_map *map) {
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        exit_with_error("Failed to open map file");

    char *line;
    map->rows = 0;
    map->cols = 0;

    while ((line = get_next_line(fd)) != NULL) {
        int len = ft_strlen(line);
        if (line[len - 1] == '\n')
            len--;  // Don't count the newline character
        if (map->rows == 0)
            map->cols = len;
        else if (len != map->cols)
            exit_with_error("Map is not rectangular");
        map->rows++;
        free(line);
    }
    close(fd);

    map->data = malloc(sizeof(char *) * map->rows);
    fd = open(file, O_RDONLY);
    int i = 0;
    while (i < map->rows) {
        line = get_next_line(fd);
        map->data[i] = line;
        i++;
    }
    close(fd);
}

void validate_map(t_map *map) {
    int p_count = 0, e_count = 0, c_count = 0;
    int i = 0;

   while (i < map->rows) {
        int j = 0;
        while (j < map->cols) {
            if (i == 0 || i == map->rows - 1 || j == 0 || j == map->cols - 1) {
                if (map->data[i][j] != '1')
                    exit_with_error("Map not surrounded by walls");
            }
            if (map->data[i][j] == 'P') {
                p_count++;
                map->player = (t_point){j, i};
            } else if (map->data[i][j] == 'E') {
                e_count++;
                map->exit = 1;
            } else if (map->data[i][j] == 'C') {
                c_count++;
            } else if (map->data[i][j] != '0' && map->data[i][j] != '1') {
                exit_with_error("Invalid character in map");
            }
            j++;
        }
        i++;
    }

    if (p_count != 1 || e_count != 1 || c_count < 1)
        exit_with_error("Invalid number of P/E/C");

    bfs(map, map->player);
}

void bfs(t_map *map, t_point start) {
    int visited[map->rows][map->cols];
    memset(visited, 0, sizeof(visited));
    t_point queue[map->rows * map->cols];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start.y][start.x] = 1;

    while (front < rear) {
        t_point current = queue[front++];
        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
        int i = 0;

        while (i < 4) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < map->cols && ny >= 0 && ny < map->rows &&
                !visited[ny][nx] && map->data[ny][nx] != '1') {
                visited[ny][nx] = 1;
                queue[rear++] = (t_point){nx, ny};
            }
            i++;
        }
    }

    int i = 0;
    while (i < map->rows) {
        int j = 0;
        while (j < map->cols) {
            if ((map->data[i][j] == 'C' || map->data[i][j] == 'E') && !visited[i][j])
                exit_with_error("No valid path to collectibles/exit");
            j++;
        }
        i++;
    }
}
