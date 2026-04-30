using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace с_
{
    public partial class Form1 : Form
    {
        // Створюємо екземпляр нашого класу-контейнера
        private PanelCollection manager = new PanelCollection();

        public Form1()
        {
            InitializeComponent();

            // Автоматичне завантаження даних при старті (Вимога 7)
            manager.ImportData("frames_data.txt");
            UpdateList();
        }

        // Метод для оновлення ListBox за допомогою нашого Ітератора
        private void UpdateList()
        {
            listBoxFrames.Items.Clear();

            // Цей цикл foreach працює ТІЛЬКИ завдяки нашому PanelIterator (Вимога 3)
            foreach (HeaderPanel panel in manager)
            {
                listBoxFrames.Items.Add(panel.GetDisplayInfo());
            }
        }

        // 1. ВІДКРИВАННЯ ВІКНА (Додавання на нульову позицію)
        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                int x1 = int.Parse(txtX1.Text);
                int y1 = int.Parse(txtY1.Text);
                int x2 = int.Parse(txtX2.Text);
                int y2 = int.Parse(txtY2.Text);

                if (x1 >= x2 || y1 >= y2)
                {
                    MessageBox.Show("Помилка: права нижня точка повинна бути більшою за ліву верхню!", "Помилка координат", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                // Створення об'єкта похідного класу
                HeaderPanel newPanel = new HeaderPanel(x1, y1, x2, y2, txtBgColor.Text, txtHeaderText.Text, txtFontColor.Text);

                manager.OpenPanel(newPanel);
                UpdateList();
            }
            catch (FormatException)
            {
                MessageBox.Show("Будь ласка, введіть коректні числа для координат!", "Помилка вводу", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        // 3. ЗМІНА ФОКУСУ
        private void btnFocus_Click(object sender, EventArgs e)
        {
            if (listBoxFrames.SelectedIndex != -1)
            {
                manager.FocusPanel(listBoxFrames.SelectedIndex);
                UpdateList();
                listBoxFrames.SelectedIndex = 0; // Зберігаємо виділення на переміщеному елементі
            }
            else
            {
                MessageBox.Show("Оберіть елемент у списку!", "Увага");
            }
        }

        // 4. ЗАКРИВАННЯ (Видалення)
        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listBoxFrames.SelectedIndex != -1)
            {
                manager.ClosePanel(listBoxFrames.SelectedIndex);
                UpdateList();
            }
            else
            {
                MessageBox.Show("Оберіть елемент у списку!", "Увага");
            }
        }

        // 5. ДЕМОНСТРАЦІЯ ПОЛІМОРФІЗМУ
        private void btnPoly_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtNewColor.Text))
            {
                MessageBox.Show("Введіть новий колір у відповідне поле!", "Увага");
                return;
            }

            manager.MassUpdateStyle(txtNewColor.Text);
            UpdateList();
            MessageBox.Show("Стиль успішно оновлено. Зверніть увагу: завдяки поліморфізму змінився колір шрифту заголовка, а не фон!", "Поліморфізм");
        }

        // ТЕСТ ОПЕРАТОРА += (Зсув)
        private void btnShift_Click(object sender, EventArgs e)
        {
            if (listBoxFrames.SelectedIndex != -1)
            {
                try
                {
                    int offset = int.Parse(txtOffset.Text);
                    manager.ShiftPanel(listBoxFrames.SelectedIndex, offset);
                    UpdateList();
                }
                catch (FormatException)
                {
                    MessageBox.Show("Введіть коректне число для зсуву!", "Помилка");
                }
            }
            else
            {
                MessageBox.Show("Оберіть елемент у списку!", "Увага");
            }
        }

        // ТЕСТ ОПЕРАТОРА + (Накладання)
        private void btnCombine_Click(object sender, EventArgs e)
        {
            // Для тесту беремо перші два елементи (якщо вони є)
            if (listBoxFrames.Items.Count >= 2)
            {
                HeaderPanel combined = manager.CombinePanels(0, 1);
                MessageBox.Show("Результат спільної оболонки перших двох вікон:\n\n" + combined.GetDisplayInfo(), "Тест оператора +");
            }
            else
            {
                MessageBox.Show("Для демонстрації потрібно щонайменше 2 вікна у списку!", "Увага");
            }
        }

        // ЗБЕРЕЖЕННЯ
        private void btnSave_Click(object sender, EventArgs e)
        {
            manager.ExportData("frames_data.txt");
            MessageBox.Show("Дані успішно збережено!", "Експорт");
        }

        // ЗАВАНТАЖЕННЯ
        private void btnLoad_Click(object sender, EventArgs e)
        {
            manager.ImportData("frames_data.txt");
            UpdateList();
            MessageBox.Show("Дані успішно завантажено!", "Імпорт");
        }

        // Автоматичне збереження при закритті форми хрестиком
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            manager.ExportData("frames_data.txt");
        }
    }
}
