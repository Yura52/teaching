#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
public:
    Document(const std::string& s): content_(s) {}
    virtual ~Document() {}

    virtual void Save() const {}
    const std::string& GetContent() const {
        return content_;
    }

private:
    const std::string content_;
};

class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}

    void Save() const override {
        std::cout << GetContent() << "\n";
    }
};

class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    void Save() const override {
        std::cout << "<HTML><BODY>" << GetContent() << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<std::unique_ptr<Document>>;

void AddDocument(
    const std::string& content,
    const std::string& type,
    DocumentCollection& collection)
{
    if (type == "plain") {
        collection.push_back(std::make_unique<PlainTextDocument>(content));
    } else if (type == "html") {
        collection.push_back(std::make_unique<HTMLDocument>(content));
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection)
        doc->Save();
}
