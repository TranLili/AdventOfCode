using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace AdventOfCode2023.Solutions
{
    class Day01Part2
    {
        public int value { get; set; }
        public string filePath { get; set; }
        public List<string> numbers { get; set; }
        public Day01Part2(string filepath)
        {
            this.filePath = filepath;
        }

        public int Solution()
        {
            StreamReader reader = new StreamReader(filePath);
            string line = reader.ReadLine();
            int result = 0;
            while (line != null)
            {
                string first = GetFirst(line).ToString();
                string last = GetLast(line).ToString();
                Console.WriteLine("first is: " + first);
                Console.WriteLine("last is: " + last);
                string temp = "";
                temp += first;
                temp += last;
                result += int.Parse(temp);
                Console.WriteLine("My temp: " + temp);
                line = reader.ReadLine();
            }
            Console.WriteLine("My output: " + result);
            this.value = result;
            return this.value;
        }

        public int Convert(string number)
        {
            if (int.TryParse(number, out int value))
                return value;
            else
            {
                switch (number.ToLower())
                {
                    case "zero":
                        return 0;
                    case "orez":
                        return 0;
                    case "one":
                        return 1;
                    case "eno":
                        return 1;
                    case "two":
                        return 2;
                    case "owt":
                        return 2;
                    case "three":
                        return 3;
                    case "eerht":
                        return 3;
                    case "four":
                        return 4;
                    case "ruof":
                        return 4;
                    case "five":
                        return 5;
                    case "evif":
                        return 5;
                    case "six":
                        return 6;
                    case "xis":
                        return 6;
                    case "seven":
                        return 7;
                    case "neves":
                        return 7;
                    case "eight":
                        return 8;
                    case "thgie":
                        return 8;
                    case "nine":
                        return 9;
                    case "enin":
                        return 9;
                    default:
                        return -1;
                }
            }
        }

        string Reverse(string str)
        {
            char[] charArray = str.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        int GetFirst(string text)
        {
            Match match = Regex.Match(text, @"(?:zero|one|two|three|four|five|six|seven|eight|nine|\d+)");
            int number = match.Success ? Convert(match.Value) : -1;
            string d = number.ToString();
            char f = d[0];
            int result = (int)Char.GetNumericValue(f);
            return result;
        }

        int GetLast(string text)
        {
            string reverse = Reverse(text);
            Match match = Regex.Match(reverse, @"(?:orez|eno|owt|eerht|ruof|evif|xis|neves|thgie|enin|\d+)");
            int number = match.Success ? Convert(match.Value) : -1;
            string d = number.ToString();
            char f = d[0];
            int result = (int)Char.GetNumericValue(f);
            return result;
        }
    }
}
