using System.Collections;
using System.Collections.Generic;
using System.IO;

public class PanelCollection : IEnumerable<HeaderPanel>
{
    private List<HeaderPanel> _panels = new List<HeaderPanel>();

    // 1. Відкривання (додавання на нульову позицію)
    public void OpenPanel(HeaderPanel panel)
    {
        _panels.Insert(0, panel);
    }

    // 2. Закривання (видалення з масиву)
    public void ClosePanel(int index)
    {
        if (index >= 0 && index < _panels.Count)
        {
            _panels.RemoveAt(index);
        }
    }

    // 3. Зміна фокусу (розмістити на нульову позицію)
    public void FocusPanel(int index)
    {
        if (index > 0 && index < _panels.Count)
        {
            HeaderPanel target = _panels[index];
            _panels.RemoveAt(index);
            _panels.Insert(0, target);
        }
    }

    // 4. Поліморфічне масове оновлення стилю з використанням Ітератора!
    public void MassUpdateStyle(string newColor)
    {
        foreach (HeaderPanel panel in this)
        {
            panel.UpdateStyle(newColor);
        }
    }

    // 5. Демонстрація оператора += (зсув вікна)
    public void ShiftPanel(int index, int offset)
    {
        if (index >= 0 && index < _panels.Count)
        {
            _panels[index] += offset;
        }
    }

    // 6. Демонстрація оператора + (об'єднання двох вікон)
    public HeaderPanel CombinePanels(int id1, int id2)
    {
        if (id1 >= 0 && id1 < _panels.Count && id2 >= 0 && id2 < _panels.Count)
        {
            ScreenPanel combined = _panels[id1] + _panels[id2];
            return new HeaderPanel(combined.StartX, combined.StartY, combined.EndX, combined.EndY,
                                   combined.BgColor, "Combined", "Red");
        }
        return null;
    }

    // Читання і запис у файл
    public void ExportData(string filename)
    {
        using (StreamWriter writer = new StreamWriter(filename))
        {
            foreach (HeaderPanel panel in this)
            {
                writer.WriteLine(panel.ToString());
            }
        }
    }

    public void ImportData(string filename)
    {
        if (!File.Exists(filename)) return;

        _panels.Clear();
        string[] lines = File.ReadAllLines(filename);

        // Читаємо з кінця, щоб при вставці на індекс 0 зберігся правильний порядок
        for (int i = lines.Length - 1; i >= 0; i--)
        {
            if (!string.IsNullOrWhiteSpace(lines[i]))
            {
                _panels.Insert(0, HeaderPanel.FromString(lines[i]));
            }
        }
    }

    public List<HeaderPanel> GetAll()
    {
        return _panels;
    }

    // Зв'язуємо колекцію з нашим власним ітератором
    public IEnumerator<HeaderPanel> GetEnumerator()
    {
        return new PanelIterator(_panels);
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}