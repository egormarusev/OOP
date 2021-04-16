#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QString>
#include <map>
#include <QFile>
#include <QDataStream>
//using namespace std;

template <class K, class V> class PrefixTree
{
public:
    PrefixTree();
    PrefixTree(PrefixTree& tree);
    ~PrefixTree();
    V& operator[](const K& key) const;
    void deleteAll();
    int getCountKeys() const;
    int getCountNodes() const;
    int getMaxLength() const;
    bool Write(const QString &filename) const;
    bool Read(const QString &filename);
    bool operator==(const PrefixTree& tree);
    void addKVtoCollection(const K& key, const V& value);
    void deleteKey(const K& key);
    bool checkHaveKey(const K& key);
    QVector<K> getKeys(const K& key) const;
private:
    class Node {
    public:
        Node()
        {
            isValue = false;
            parent = NULL;
        }
        void add(const K key)
        {
            items[key] = new Node;
            items[key]->parent = this;
        }
        ~Node()
        {
            typename std::map<K, Node*>::iterator it, end;
            it = items.begin();
            end = items.end();
            while (it != end)
            {
                delete it->second;
                it++;
            }
        }
        V value;
        bool isValue = false;
        Node* parent = NULL;
        std::map<K, Node*> items;
    };

    void addKey(typename PrefixTree<K, V>::Node* root, K* key, const int i, QVector<K>* vect) const;
    int nodes; //Количество узлов
    int keys; //Количество ключей
    int maxLength; //Максимальная длина ключа
    Node* root;
};

template <class K, class V> PrefixTree<K, V>::PrefixTree()
{
    //Конструктор по умолчанию
    this->keys = 0;
    this->nodes = 0;
    this->maxLength = 0;
    this->root = new Node;
}

template <class K, class V> PrefixTree<K, V>::PrefixTree(PrefixTree &tree)
{
    //Конструктор копирования
    K empty;
    QVector<K> vect = tree.getKeys(empty);
    this->keys = 0;
    this->nodes = 0;
    this->maxLength = 0;
    this->root = new Node;
    int i = 0;
    while (i < (int)vect.size())
    {
        add(vect[i], tree[vect[i]]);
        i++;
    }
}

template <class K, class V> PrefixTree<K, V>::~PrefixTree()
{
    //Деструктор
    delete this->root;
}

template <class K, class V> void PrefixTree<K, V>::deleteAll()
{
    //Удаление всех значений
    delete this->root;
    this->nodes = 0;
    this->keys = 0;
    this->maxLength = 0;
    this->root = new Node;

}

template <class K, class V> int PrefixTree<K, V>::getCountKeys() const
{
    //Количество ключей
    return this->keys;
}

template <class K, class V> int PrefixTree<K, V>::getCountNodes() const
{
    //Количество узлов
    return this->nodes;
}
template<class K, class V> bool PrefixTree<K, V>::Write(const QString &filename) const
{
    //Сохранение коллекции в файл
    if (!filename.endsWith(".lab")) return false;
    QFile file(filename);
    if (file.open(QFile::WriteOnly)) {
        K empty;
        QVector<K> keys = getKeys(empty);
        int i = 0;
        QDataStream out(&file);
        out << keys;
        QVector<V> values;
        while (i < (int)keys.size()) {
            values.push_back((*this)[keys[i]]);
            i++;
        }
        out << values;
        file.close();
        return true;
    }
    else
        return false;
}

template<class K, class V> bool PrefixTree<K, V>::Read(const QString &filename)
{
    //Загрузка префиксного дерева из файла
    if (!filename.endsWith(".lab")) return false;
    QFile file(filename);
    if (file.open(QFile::ReadOnly))
    {
        QDataStream in(&file);
        deleteAll();
        QVector<K> keys;
        in >> keys;
        QVector<V> values;
        in >> values;
        for (int i = 0; i<keys.size(); i++)
            addKVtoCollection(keys[i], values[i]);
        file.close();
        return true;
    }
    else
        return false;
}

template <class K, class V> bool PrefixTree<K, V>::operator==(const PrefixTree &tree)
{
    // == равенство 2 деревьев
    K empty;
    QVector<K> vect1 = getKeys(empty);
    QVector<K> vect2 = tree.getKeys(empty);
    int i = 0;
    while (i < (int)vect1.size())
    {
        try
        {
            if ((*this)[vect1[i]] != tree[vect1[i]])
                return false;
        }
        catch (std::out_of_range)
        {
            return false;
        }
        i++;
    }
    i = 0;
    while (i < (int)vect2.size())
    {
        try
        {
            if ((*this)[vect2[i]] != tree[vect2[i]])
                return false;
        }  catch (std::out_of_range)
        {
            return false;
        }
        i++;
    }
    return true;
}

template <class K, class V> void PrefixTree<K, V>::addKVtoCollection(const K& key, const V& value)
{
    //Добавление пары ключ-значение в коллекцию
    int i=0;
    Node* t = this->root;
    while (i<(int)key.size())
    {
        K newKey = {key[i]};
        if (t->items.count(newKey) == 0)
        {
            t->add(newKey);
            this->nodes++;
        }
        t = t->items.at(newKey);
        i++;
    }
    if (t->isValue)
        this->keys--;
    t->value = value;
    t->isValue = true;
    if (this->maxLength < i)
        this->maxLength = i;
    this->keys++;
}

template <class K, class V> void PrefixTree<K, V>::deleteKey(const K& key)
{
    //Удаление ключа
    if (checkHaveKey(key)) {
        int i=0;
        Node* t = this->root;
        while (i<(int)key.size())
        {
            std::map<K, Node*> dict = t->items;
            K newKey = {key[i]};
            t = dict[newKey];
            i++;
        }
        i--;
        if (t->items.size() != 0)
        {
            t->isValue = false;
            this->keys--;
            return;
        }
        while (t->parent)
            if ((t->parent->items.size() == 1) && (t->parent->isValue == 0))
            {
                t = t->parent;
                i--;
                this->nodes--;
            }
            else
                break;
        if (t->parent)
        {
            K new_key = {key[i]};
            t->parent->items.erase(new_key);
            delete t;
            this->nodes--;
        }
        else
        {
            delete t;
            this->root = new Node;
        }
        this->keys--;
    }
}

template <class K, class V> V& PrefixTree<K, V>::operator[](const K& key) const
{
    //Перегрузка [] - получение значения по ключу
    //При отсутствии ключа - исключение out_of_range
    int i=0;
    Node* t = this->root;
    while (i<(int)key.size())
    {
        std::map<K, Node*> dict = t->items;
        K new_key = {key[i]};
        if (t->items.count(new_key))
            t = dict[new_key];
        else
            throw std::out_of_range("Key error");
        i++;
    }
    if (t->isValue)
        return t->value;
    else
        throw std::out_of_range("Key error");
}

template <class K, class V> bool PrefixTree<K, V>::checkHaveKey(const K& key)
{
    //Проверка является ли данный ключ ключом коллекции
    int i=0;
    Node* t = this->root;
    while (i<(int)key.size())
    {
        std::map<K, Node*> dict = t->items;
        K new_key = {key[i]};
        if (t->items.count(new_key))
            t = dict[new_key];
        else
            return false;
        i++;
    }
    return t->isValue;
}


template<class K, class V> QVector<K> PrefixTree<K, V>::getKeys(const K &key) const
{
    //Получение вектора ключей, начинающихся с заданной последовательности
    QVector<K> vect;
    int i=0;
    typename PrefixTree<K, V>::Node* t = this->root;
    K* keyitem = new K;
    while (i<(int)key.size())
    {
        std::map<K, typename PrefixTree<K, V>::Node*> dict = t->items;
        K new_key = {key[i]};
        if (t->items.count(new_key))
        {
            t = dict[new_key];
            keyitem->push_back(key[i]);
        }
        else
            return vect;
        i++;
    }
    addKey(t, keyitem, i, &vect);
    delete keyitem;
    return vect;
}



template <class K, class V> int PrefixTree<K, V>::getMaxLength() const
{
    //Максимальная длина ключа
    return this->maxLength;
}

template<class K, class V> void PrefixTree<K, V>::addKey(typename PrefixTree<K, V>::Node* root, K* key, const int i, QVector<K>* vect) const
{
    //Добавление ключа в вектор
    if (root->isValue) {
        vect->push_back(*key);
    }
    typename std::map<K, typename PrefixTree<K, V>::Node*>::iterator it, end;
    it = root->items.begin();
    end = root->items.end();
    while (it != end)
    {
        key->push_back((it->first)[0]);
        addKey(it->second, key, i+1, vect);
        key->pop_back();
        it++;
    }
}
#endif // TEMPLATE_H




