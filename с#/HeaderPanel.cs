using System;

public class HeaderPanel : ScreenPanel
{
    public string HeaderText { get; set; }
    public string FontColor { get; set; }

    public HeaderPanel() : base()
    {
        HeaderText = "Untitled";
        FontColor = "Black";
    }

    public HeaderPanel(int x1, int y1, int x2, int y2, string bg, string text, string textColor)
        : base(x1, y1, x2, y2, bg)
    {
        HeaderText = text;
        FontColor = textColor;
    }

    public HeaderPanel(HeaderPanel other) : base(other)
    {
        HeaderText = string.Copy(other.HeaderText);
        FontColor = string.Copy(other.FontColor);
    }

    // Перевантаження операції + для числа. 
    // У C# це автоматично дозволяє використовувати оператор += для зсуву!
    public static HeaderPanel operator +(HeaderPanel panel, int offset)
    {
        return new HeaderPanel(
            panel.StartX + offset, panel.StartY + offset,
            panel.EndX + offset, panel.EndY + offset,
            panel.BgColor, panel.HeaderText, panel.FontColor
        );
    }

    // Поліморфізм: перевизначення методу
    public override void UpdateStyle(string newColor)
    {
        FontColor = newColor; // Змінюємо колір тексту, а не фону!
    }

    public override string GetDisplayInfo()
    {
        return base.GetDisplayInfo() + $" | Шапка: <{HeaderText}>, Колір тексту: {FontColor}";
    }

    // Заміна оператора <<
    public override string ToString()
    {
        return base.ToString() + $"|{HeaderText}|{FontColor}";
    }

    // Заміна оператора >> (Читання з рядка файлу)
    public static HeaderPanel FromString(string data)
    {
        string[] parts = data.Split('|');
        if (parts.Length == 7)
        {
            return new HeaderPanel(
                int.Parse(parts[0]), int.Parse(parts[1]),
                int.Parse(parts[2]), int.Parse(parts[3]),
                parts[4], parts[5], parts[6]
            );
        }
        throw new FormatException("Невірний формат даних у файлі.");
    }
}