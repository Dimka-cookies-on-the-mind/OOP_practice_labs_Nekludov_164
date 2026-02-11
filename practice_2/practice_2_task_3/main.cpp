#include <iostream>
#include <memory>

using namespace std;

class Document {
public:
    virtual void open() const = 0;
    virtual void close() const = 0;

    virtual ~Document() = default;
};

class TextDocument : public Document {
public:
    void open() const override {
        cout << "Opening a text document" << endl;
    }
    void close() const override {
        cout << "Closing a text document" << endl;
    }
};

class SpreadsheetDocument : public Document {
public:
    void open() const override {
        cout << "Opening a spreadsheet document" << endl;
    }
    void close() const override {
        cout << "Closing a spreadsheet document" << endl;
    }
};

class Application {
public:
    virtual unique_ptr<Document> create_document() const = 0;

    virtual ~Application() = default;
};

class TextApplication : public Application {
public:
    unique_ptr<Document> create_document() const override {
        return make_unique<TextDocument>();
    }
};

class SheetApplication : public Application {
public:
    unique_ptr<Document> create_document() const override {
        return make_unique<SpreadsheetDocument>();
    }
};

int main()
{
    //unique_ptr<Application> prilojenie = make_unique<TextApplication>();
    Application* prilojenie = new TextApplication();

    auto doc = prilojenie->create_document();

    doc->open();
    doc->close();

    delete prilojenie;
    prilojenie = nullptr;

    return 0;
}
