using System;

public class ScreenPanel
{
    // Властивості (замінюють класичні гетери та сетери C++)
    public int StartX { get; set; }
    public int StartY { get; set; }
    public int EndX { get; set; }
    public int EndY { get; set; }
    public string BgColor { get; set; }

    // Конструктор за замовчуванням
    public ScreenPanel()
    {
        StartX = 0; StartY = 0; EndX = 0; EndY = 0; BgColor = "None";
    }

    // Конструктор ініціалізації
    public ScreenPanel(int x1, int y1, int x2, int y2, string bg)
    {
        StartX = x1; StartY = y1; EndX = x2; EndY = y2; BgColor = bg;
    }

    // Конструктор копіювання
    public ScreenPanel(ScreenPanel other)
    {
        StartX = other.StartX; StartY = other.StartY;
        EndX = other.EndX; EndY = other.EndY;
        BgColor = string.Copy(other.BgColor);
    }

    // Перевантаження операції + для накладання двох вікон
    public static ScreenPanel operator +(ScreenPanel a, ScreenPanel b)
    {
        return new ScreenPanel(
            Math.Min(a.StartX, b.StartX), Math.Min(a.StartY, b.StartY),
            Math.Max(a.EndX, b.EndX), Math.Max(a.EndY, b.EndY),
            a.BgColor
        );
    }

    // Поліморфічний метод зміни стилю
    public virtual void UpdateStyle(string newColor)
    {
        BgColor = newColor; // У базовому класі міняємо фон
    }

    // Метод для зручного виведення на екран
    public virtual string GetDisplayInfo()
    {
        return $"Фрейм [{StartX}:{StartY} -> {EndX}:{EndY}], Фон: {BgColor}";
    }

    // Заміна оператора << для збереження у файл
    public override string ToString()
    {
        return $"{StartX}|{StartY}|{EndX}|{EndY}|{BgColor}";
    }
}