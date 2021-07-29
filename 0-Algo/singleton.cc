class Singleton {
   private:
    static Singleton* _instance;
    Singleton() {}

   public:
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }
        return _instance;
    }
};
