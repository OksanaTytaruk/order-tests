# Order tests (C++ with GoogleTest)

Простий проєкт для повного покриття unit-тестами коду `Order`/`Money`.

## Що в комплекті
- `src/` — реалізація (order.h, order.cpp)
- `tests/` — google-test тести (order_tests.cpp)
- `CMakeLists.txt` — для збірки з FetchContent googletest
- `.github/workflows/ci.yml` — (опційно) CI для GitHub Actions
- `.gitignore`

## Швидкий старт (Ubuntu)
1. Встанови залежності:
```bash
sudo apt update
sudo apt install -y build-essential cmake lcov
```

2. Збірка та запуск тестів:
```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest --output-on-failure
# або ./tests_exec
```

3. Звіт про покриття:
```bash
# перезбірка з прапором coverage
cd ..
rm -rf build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage" ..
cmake --build .
./tests_exec

lcov --capture --directory . --output-file coverage.info
lcov --remove coverage.info '/usr/*' --output-file coverage.info
genhtml coverage.info --output-directory coverage
# відкрий build/coverage/index.html
```

## Пуш в GitHub
```bash
git init
git add .
git commit -m "Add implementation and unit tests"
# створи репо на GitHub і додай remote
git remote add origin git@github.com:YOUR_USERNAME/your-repo.git
git branch -M main
git push -u origin main
```

## Потрібна допомога?
Напиши — допоможу з GitHub Actions, або адаптацією під Windows/macOS.
