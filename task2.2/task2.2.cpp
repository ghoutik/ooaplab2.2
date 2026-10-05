#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Jewelry
{
private:
    string type;
    string metal;
    double weight;
    int complexity;
    double metalPrice;
    double workPrice;

public:
    Jewelry()
    {
        type = "";
        metal = "";
        weight = 0;
        complexity = 0;
        metalPrice = 0;
        workPrice = 0;
    }

    void setType(string value)
    {
        type = value;
    }

    void setMetal(string value)
    {
        metal = value;
    }

    void setWeight(double value)
    {
        weight = value;
    }

    void setComplexity(int value)
    {
        complexity = value;
    }

    void setMetalPrice(double value)
    {
        metalPrice = value;
    }

    void setWorkPrice(double value)
    {
        workPrice = value;
    }

    double getPrice() const
    {
        return weight * metalPrice + complexity * workPrice;
    }

    void show() const
    {
        cout << left
            << setw(20) << type
            << setw(12) << metal
            << setw(10) << weight
            << setw(12) << complexity
            << fixed << setprecision(2)
            << getPrice() << " UAH" << endl;
    }
};

class JewelryBuilder
{
protected:
    Jewelry* jewelry;

public:
    JewelryBuilder()
    {
        jewelry = nullptr;
    }

    virtual ~JewelryBuilder()
    {
        delete jewelry;
    }

    virtual void reset() = 0;
    virtual void setType(string type) = 0;
    virtual void setMetal() = 0;
    virtual void setWeight(double weight) = 0;
    virtual void setComplexity(int complexity) = 0;
    virtual void setMetalPrice() = 0;
    virtual void setWorkPrice(double price) = 0;

    Jewelry* getResult()
    {
        Jewelry* result = jewelry;
        jewelry = nullptr;
        return result;
    }
};

class GoldJewelryBuilder : public JewelryBuilder
{
public:
    void reset() override
    {
        jewelry = new Jewelry();
    }

    void setType(string type) override
    {
        jewelry->setType(type);
    }

    void setMetal() override
    {
        jewelry->setMetal("Gold");
    }

    void setWeight(double weight) override
    {
        jewelry->setWeight(weight);
    }

    void setComplexity(int complexity) override
    {
        jewelry->setComplexity(complexity);
    }

    void setMetalPrice() override
    {
        jewelry->setMetalPrice(2500);
    }

    void setWorkPrice(double price) override
    {
        jewelry->setWorkPrice(price);
    }
};

class SilverJewelryBuilder : public JewelryBuilder
{
public:
    void reset() override
    {
        jewelry = new Jewelry();
    }

    void setType(string type) override
    {
        jewelry->setType(type);
    }

    void setMetal() override
    {
        jewelry->setMetal("Silver");
    }

    void setWeight(double weight) override
    {
        jewelry->setWeight(weight);
    }

    void setComplexity(int complexity) override
    {
        jewelry->setComplexity(complexity);
    }

    void setMetalPrice() override
    {
        jewelry->setMetalPrice(35);
    }

    void setWorkPrice(double price) override
    {
        jewelry->setWorkPrice(price);
    }
};

class JewelryDirector
{
public:
    Jewelry* constructEarrings(JewelryBuilder* builder)
    {
        builder->reset();
        builder->setType("Earrings");
        builder->setMetal();
        builder->setWeight(8);
        builder->setComplexity(2);
        builder->setMetalPrice();
        builder->setWorkPrice(500);

        return builder->getResult();
    }

    Jewelry* constructRing(JewelryBuilder* builder)
    {
        builder->reset();
        builder->setType("Ring");
        builder->setMetal();
        builder->setWeight(6);
        builder->setComplexity(3);
        builder->setMetalPrice();
        builder->setWorkPrice(500);

        return builder->getResult();
    }

    Jewelry* constructChain(JewelryBuilder* builder)
    {
        builder->reset();
        builder->setType("Chain");
        builder->setMetal();
        builder->setWeight(15);
        builder->setComplexity(4);
        builder->setMetalPrice();
        builder->setWorkPrice(500);

        return builder->getResult();
    }

    Jewelry* constructPendant(JewelryBuilder* builder)
    {
        builder->reset();
        builder->setType("Pendant");
        builder->setMetal();
        builder->setWeight(5);
        builder->setComplexity(3);
        builder->setMetalPrice();
        builder->setWorkPrice(500);

        return builder->getResult();
    }

    Jewelry* constructBracelet(JewelryBuilder* builder)
    {
        builder->reset();
        builder->setType("Bracelet");
        builder->setMetal();
        builder->setWeight(20);
        builder->setComplexity(4);
        builder->setMetalPrice();
        builder->setWorkPrice(500);

        return builder->getResult();
    }
};

void showCatalog(JewelryBuilder* builder)
{
    JewelryDirector director;

    Jewelry* products[5];

    products[0] = director.constructEarrings(builder);
    products[1] = director.constructRing(builder);
    products[2] = director.constructChain(builder);
    products[3] = director.constructPendant(builder);
    products[4] = director.constructBracelet(builder);

    cout << endl;

    cout << left
        << setw(20) << "Product"
        << setw(12) << "Metal"
        << setw(10) << "Weight"
        << setw(12) << "Complexity"
        << "Price" << endl;

    cout << string(70, '-') << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i]->show();
        delete products[i];
    }
}

int main()
{
    int choice;

    do
    {
        cout << endl;
        cout << "======================================" << endl;
        cout << "           JEWELRY BUILDER" << endl;
        cout << "======================================" << endl;
        cout << "1 - Gold jewelry catalog" << endl;
        cout << "2 - Silver jewelry catalog" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";

        cin >> choice;

        JewelryBuilder* builder = nullptr;

        switch (choice)
        {
        case 1:
            builder = new GoldJewelryBuilder();

            cout << endl;
            cout << "GOLD JEWELRY CATALOG" << endl;

            showCatalog(builder);

            delete builder;
            break;

        case 2:
            builder = new SilverJewelryBuilder();

            cout << endl;
            cout << "SILVER JEWELRY CATALOG" << endl;

            showCatalog(builder);

            delete builder;
            break;

        case 0:
            cout << "Program finished." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}