using System;

namespace BinarySearch_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            var array = new[] {1, 2, 5, 9, 10};

            int index = BinarySearch<int>(array, 2, (small, big) => small < big);

            Console.WriteLine(index);

            var array2 = new[] { "1",  "2", "3", "5", "8"};


            index = BinarySearch<string>(array2, "8", (small, big) => int.Parse(small) < int.Parse(big));

            Console.WriteLine(index);

            Console.ReadKey(); 
        }

        static int BinarySearch<T>(T[] array, T target, Func<T, T, bool> compare)
        {
            int first = 0;
            int last = array.Length -1;
            int mid;

            while (first <= last)
            {
                mid = (first + last) / 2;

                if (array[mid].Equals(target))
                {
                    return mid;
                }

                if (compare(target, array[mid]))
                    last = mid - 1;
                else
                    first = mid + 1;
            }

            return -1;
        }
    }
}
