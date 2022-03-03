#include <random>

using namespace std;

int main(void)
{
    // 시드값을 얻기 위한 random_device 생성.
    random_device rd;
    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    mt19937 gen(rd());
    // mt19937 gen(123);
    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    // uniform_int_distribution<int> dis(0, 99);

    uniform_int_distribution<int> dis_airport_num(3, 10000); // 주어진 공항 수는 3개 이상 10,000개 이하
    uniform_int_distribution<int> dis_alphabet(65, 90);      // 'A' ~ 'Z'

    int airport_num = dis_airport_num(gen);
    airport_num = 800;

    string fr = "ICN";
    vector<vector<string>> tickets;
    for (int i = 0; i < airport_num; i++)
    {
        vector<string> ticket;
        string to = "";
        ticket.push_back(fr);
        for (int j = 0; j < 3; j++)
        {
            to += char(dis_alphabet(gen));
        }
        if (fr != to) // 티켓의 출발지와 도착지가 달라지도록 처리
        {
            ticket.push_back(to);
            fr = to;
            tickets.push_back(ticket);
        }
        else
            i--;
    }

    shuffle(tickets.begin(), tickets.end(), gen); // 배열의 순서를 랜덤으로 셔플

    return 0;
}