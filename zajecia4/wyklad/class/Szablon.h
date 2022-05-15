#ifndef CLASS_SZABLON

#define CLASS_SZABLON

class Szablon {
private:
public:
  Szablon();
  ~Szablon();
};

template <typename Type1, typename Type2> Type1 f_add(Type1 x, Type2 y) {
  return x + y;
}

#endif // CLASS_SZBLON