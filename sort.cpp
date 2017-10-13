#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist]() -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main()
{
    std::cout << " Enter the size of the array " << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> v = generate_random_vector<int> (n, -50, 50);
    std::cout << " Unordered array " << std::endl;
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        for (int j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    std::cout << " Ordered array" << std::endl;
    for (int i = 0; i < v.size(); ++i)
        {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    return 0;
}
