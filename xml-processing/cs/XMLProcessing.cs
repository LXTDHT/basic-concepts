using System.Reflection.Metadata;
using System.Xml.Linq;

class XMLProcessing
{
    const string FILE_PATH = "../test.xml";
    static XDocument doc = XDocument.Load(FILE_PATH);

    static void Main(string[] args)
    {
        foreach (XElement e in doc.Descendants())
        {
            System.Console.WriteLine(e.Name);
        }
    }
}