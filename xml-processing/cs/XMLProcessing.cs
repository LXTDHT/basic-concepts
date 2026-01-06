using System.Diagnostics.Tracing;
using System.Xml.Linq;

class XMLProcessing
{
    // const bool DEBUG = true; // true when running on Visual Studio Code, false when running the dotnet command from the source code file directory
    /* true when running on Visual Studio Code,
    false when running the dotnet command from the source code file directory */
    const string FILE_PATH = true ? "xml-processing/test.xml" : "../test.xml";
    // static readonly XDocument doc = XDocument.Load(FILE_PATH);

    static void Main(string[] args)
    {
        OutputXElements(XDocument.Load(FILE_PATH).Elements());
    }

    static void OutputXElements(IEnumerable<XElement> elements, string tab = "")
    {
        string output;
        bool isParent;
        foreach (XElement e in elements)
        {
            isParent = e.HasElements;
            output = (e.HasAttributes ? e.Attributes().First().Value : "")
            + tab + e.Name + (isParent ? "" : ": " + e.Value);
            System.Console.WriteLine(output);
            if (isParent)
            {
                tab += "\t";
                OutputXElements(e.Elements(), tab);
                tab = tab.Remove(tab.IndexOf("\t"), 1);
            }
        }
    }
}