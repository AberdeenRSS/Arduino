template<class T>
T* getSingleton() {
    static T obj;
    return &obj;
}