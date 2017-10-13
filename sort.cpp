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
    // 1
    std::cout << " Enter the size of the array " << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> v = generate_random_vector<int>(n, -50, 50);
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
    // 2
    std::cout << " Enter the size of the array one " << std::endl;
    int size_array1 = 0;
    std::cin >> size_array1;
    std::vector<int> v1 = generate_random_vector<int>(size_array1, -50, 50);
    for (int i = 0; i < v1.size() - 1; ++i)
    {
        for (int j = 0; j < v1.size() - i - 1; ++j)
        {
            if (v1[j] > v1[j + 1])
            {
                int temp = v1[j];
                v1[j] = v1[j + 1];
                v1[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << " Enter the size of the array two " << std::endl;
    int size_array2 = 0;
    std::cin >> size_array2;
    std::vector<int> v2 = generate_random_vector<int>(size_array2, -50, 50);
    for (int i = 0; i < v2.size() - 1; ++i)
    {
        for (int j = 0; j < v2.size() - i - 1; ++j)
        {
            if (v2[j] > v2[j + 1])
            {
                int temp = v2[j];
                v2[j] = v2[j + 1];
                v2[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int>  vector = { v1 };
    for (int i = 0; i < v1.size(); ++i)
    {
        vector.push_back(v2[i]);
    }
    int temp = vector[0];
    for (int i = 0; i < vector.size() - 1; ++i)
    {
        for (int j = 0; j < vector.size() - i - 1; ++j)
        {
            if (vector[j] > vector[j + 1])
            {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    std::cout << " Ordered array" << std::endl;
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << " ";
    }
    system("pause");
    return 0;
}
