#include <random>
#include <ctime>
using namespace std;
int main() {
        mt19937 gen((unsigned int)time(NULL));
        uniform_int_distribution<int> distribution(0, 2);
        int judge = distribution(gen);
        printf("%d",judge);
        return 0;
}
