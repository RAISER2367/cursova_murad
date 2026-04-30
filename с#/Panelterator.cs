using System;
using System.Collections;
using System.Collections.Generic;

public class PanelIterator : IEnumerator<HeaderPanel>
{
    private List<HeaderPanel> _collection;
    private int _position = -1;

    public PanelIterator(List<HeaderPanel> collection)
    {
        _collection = collection;
    }

    public HeaderPanel Current
    {
        get
        {
            if (_position >= 0 && _position < _collection.Count)
                return _collection[_position];
            throw new InvalidOperationException();
        }
    }

    object IEnumerator.Current => Current;

    public bool MoveNext()
    {
        if (_position < _collection.Count - 1)
        {
            _position++;
            return true;
        }
        return false;
    }

    public void Reset()
    {
        _position = -1;
    }

    public void Dispose() { } // Вимагається інтерфейсом
}