int n, m;
int graph[1000][1000];

// N, M을 공백을 기준으로 구분하여 입력 받기
cin >> n >> m;
// 2차원 리스트의 맵 정보 입력 받기
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        scanf("%1d", &graph[i][j]);
    }
}