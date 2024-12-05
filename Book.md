# std::enable_shared_from_this
- 会自动定义一个 shared_from_this() 方法，返回一个 shared_ptr，指向当前对象
```cpp

class node : public std::enable_shared_from_this<node> {
    //...
};
node* p = new node();
auto ptr = p->shared_from_this();

```

# Q_PROPERTY
```cpp

class WidTest : public QWidget{
    Q_OBJECT
    Q_PROPERTY(int temp READ getTemp WRITE setTemp NOTIFY tempChanged FINAL);
public:
    WidTest(QWidget *parent = nullptr);
    ~WidTest() = default;

    void setTemp(int t);
    int getTemp();
private:
    template <typename T> bool setVal(T& savedVal, T newVal);
signals:
    void tempChanged(int val);
private:
    std::mutex m_mtx;
    int temp = 0;
};

void WidTest::setTemp(int t){
    std::unique_lock<std::mutex> lock(m_mtx);
    if(setVal(temp, t)){
        emit tempChanged(t);
    }
}
int WidTest::getTemp(){
    return temp;
}

template <typename T>
bool WidTest::setVal(T& savedVal, T newVal) {
    std::unique_lock<std::mutex> lock(m_mtx);
    if (savedVal != newVal) {
        savedVal = newVal;
        return true;
    }
    return false;
}
```


# QJsonObject
```cpp
QJsonObject json;
json.insert("name", "zhangsan");
json.insert("age", 18);
json.insert("sex", "male");
json.insert("address", "beijing");

QJsonArray colorArray1;
colorArray1.append("black");
colorArray1.append("white");
json.insert("color", colorArray1);

QJsonValue vipValue = json.value("name");
qDebug() << vipValue.toString();
```

# HttpRequest
```cpp
#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    HTTPManager(QObject *parent = nullptr);
    ~HTTPManager();
    void postData(QString str);
    void getData();
private Q_SLOTS:
    void replyFinished(QNetworkReply *rep);
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
};



HttpClient::HttpClient() {
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &HttpClient::onFinished);
    QUrl url("http://www.baidu.com");
    manager->get(QNetworkRequest(url));
}
void HttpClient::onFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Response:" << reply->readAll();
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

```



# Q_DECLARE_METATYPE
自定义类型注册，用于QVariant
# QVariant
```cpp
std::array<QVariant, 4> args = { QVariant(1), QVariant(2), QVariant(3), QVariant(4) };
for (const QVariant& arg : args) {
    std::cout << arg.toInt() << std::endl;
}
```