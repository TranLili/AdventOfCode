using System;
using System.IO;
using System.Reflection.PortableExecutable;

namespace AdventOfCode2023.Solutions
{
    class Day01Part1
    {
        public int value { get; set; }
        public string filePath { get; set; }
        public Day01Part1(string filePath)
        {
            this.filePath = filePath;
            
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
                        value += int.Parse(digits);
                        break;
                    }
                }
            }
            this.value = value;
            return value;
        }
    }
}