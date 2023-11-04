#include<iostream>
#include<fstream>
#include<array>

const int grid_len = 20;
const int grid_height = 20;
const int grid_size = grid_len * grid_height;

std::ifstream& operator>>(std::ifstream& ifs, std::array<int, grid_size>& arr)
{
    int count = 0;
    while(ifs.good())
    {
        ifs >> arr[count];
        ++count;
    }
    return ifs;
}

int findLargestProduct(std::array<int, grid_size>& arr)
{
    int largest = 0;
    int temp = 0;
    int index = 0;

    int vert_offset = grid_len;
    int diag_offset = grid_len + 1;

    for(int i = 0; i < grid_height; ++i)
    {
        for(int j = 0; j < grid_len; ++j)
        {
            index = i * vert_offset + j;

            // check horizontally
            if(j <= grid_len - 4)
            {
                temp = arr[index] * arr[index+1] * arr[index+2] * arr[index+3];
                largest = temp > largest ? temp : largest;
            }

            // check vertically
            if(i <= grid_height - 4)
            {
                temp = arr[index] * arr[index + vert_offset] * arr[index + vert_offset * 2] * arr[index + vert_offset * 3];
                largest = temp > largest ? temp : largest;
            }

            // check diagonally
                // southeast
            if(j <= grid_len - 4 && i <= grid_height - 4)
            {
                temp = arr[index] * arr[index + diag_offset] * arr[index + diag_offset * 2] * arr[index + diag_offset * 3];
                largest = temp > largest ? temp : largest;               
            }
                // southwest
            if(j > 2 && i <= grid_height - 4)
            {
                temp = arr[index] * arr[index + diag_offset - 2] * arr[index + diag_offset * 2 - 4] * arr[index + diag_offset * 3 - 6];
                largest = temp > largest ? temp : largest;
            }
        }
    }

    return largest;
}

int main(void)
{
    // read file into array
    const char* ifname{"input.txt"};
    std::ifstream ifs{ifname};
    ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);

    std::array<int,grid_size>  numbers;

    ifs >> numbers;

    std::cout << findLargestProduct(numbers);

    return 0;
}