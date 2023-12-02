using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace AdventOfCode2023.Solutions.Day01Part2
{
    class Day01Part2
    {
        public int value { get; set; }
        public string filePath { get; set; }
        public List<string> numbers { get; set; }
        public Day01Part2(string filepath)
        {
            this.filePath = filepath;
            this.numbers = new List<string>();
            numbers.Add("zero");
            numbers.Add("one");
            numbers.Add("two");
            numbers.Add("three");
            numbers.Add("four");
            numbers.Add("five");
            numbers.Add("six");
            numbers.Add("seven");
            numbers.Add("eight");
            numbers.Add("nine");
        }

        public int Solution(List<string> lines)
        {
            StreamReader reader = new StreamReader(filePath);
            string line = reader.ReadLine();

            while (line != null)
            {
                lines.Add(line);
                line = reader.ReadLine();
            }

            Dictionary<string, int> dictionary = new Dictionary<string, int>();
            dictionary.Add("one", 1);
            dictionary.Add("two", 2);
            dictionary.Add("three", 3);
            dictionary.Add("four", 4);
            dictionary.Add("five", 5);
            dictionary.Add("six", 6);
            dictionary.Add("seven", 7);
            dictionary.Add("eight", 8);
            dictionary.Add("nine", 9);


            foreach(string text in lines)
            {

            }


            foreach (string text in lines)
            {
                string digits = "";
                for (int i = 0; i < text.Length; i++)
                {
                    if (char.IsNumber(text[i]))
                    {
                        digits += text[i];
                        break;
                    }
                }

                for (int i = text.Length - 1; i >= 0; i--)
                {
                    if (char.IsNumber(text[i]))
                    {
                        digits += text[i];
                        Console.WriteLine("The number is: " + digits);
                        value += int.Parse(digits);
                        break;
                    }
                }
            }
            Console.WriteLine("My output: " + value);
            this.value = value;
            return value;
        }

        string GetFirst(string text)
        {
            Match match = Regex.Matches()
        }

    }
}
