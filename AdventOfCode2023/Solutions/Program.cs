using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AdventOfCode2023.Solutions;

namespace AdventOfCode2023
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string directory = @"C:\Users\tranl\_programming\AdventOfCode\AdventOfCode2023\Inputs\";
            string fileName = "Day01Part2.txt";
            string path = Path.Combine(directory, fileName);
            Day01Part2 sol = new(path);
            int result = sol.Solution();
        }
    }
}
