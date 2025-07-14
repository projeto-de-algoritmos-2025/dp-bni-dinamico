typedef struct Fim {
    int id, f;
} Fim;

int cmp(const void *a, const void *b) {
    return ((Fim *)a)->f - ((Fim *)b)->f;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int busca_p(Fim *fim, int **events, int i) {
    int low = 0, high = i - 1, res = -1;
    int start_time = events[fim[i].id][0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (events[fim[mid].id][1] < start_time) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    Fim fim[eventsSize];
    int p[eventsSize];

    for (int i = 0; i < eventsSize; i++) {
        fim[i].id = i;
        fim[i].f = events[i][1];
    }

    qsort(fim, eventsSize, sizeof(Fim), cmp);

    for (int i = 0; i < eventsSize; i++) {
        p[i] = busca_p(fim, events, i);
    }

    int **dp = malloc(eventsSize * sizeof(int *));
    for (int i = 0; i < eventsSize; i++) {
        dp[i] = malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++) dp[i][j] = 0;
    }

    for (int i = 0; i < eventsSize; i++) {
        for (int j = 1; j <= k; j++) {
            int incluir = events[fim[i].id][2];
            if (p[i] != -1)
                incluir += dp[p[i]][j - 1];
            int excluir = (i > 0) ? dp[i - 1][j] : 0;
            dp[i][j] = max(incluir, excluir);
        }
    }

    int resultado = dp[eventsSize - 1][k];
    for (int i = 0; i < eventsSize; i++) free(dp[i]);
    free(dp);
    return resultado;
}
