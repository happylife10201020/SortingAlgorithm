import random

# --- 설정값 ---
LENGTH = random.randint(0, 1000)
FILENAME = "input.txt"

# --- 파일 생성 함수 ---
def write_to_file(data, filename):
    with open(filename, "w") as f:
        f.write(f"{len(data)}\n")
        f.write(" ".join(map(str, data)))
    #print(f"'{filename}' 파일 생성이 완료되었습니다.")

# --- 특이 케이스 생성 함수들 ---
def generate_nearly_sorted(length):
    #print(">> 거의 정렬된 데이터를 생성합니다.")
    data = list(range(length))
    swaps = int(length * 0.05)
    for _ in range(swaps):
        i, j = random.sample(range(length), 2)
        data[i], data[j] = data[j], data[i]
    return data

def generate_reverse_sorted(length):
    #print(">> 역순 정렬된 데이터를 생성합니다.")
    return list(range(length - 1, -1, -1))

def generate_with_many_duplicates(length):
    #print(">> 중복값이 많은 데이터를 생성합니다.")
    num_unique_values = max(1, int(length * 0.01))
    return [random.randint(0, num_unique_values) for _ in range(length)]

def generate_all_same(length):
    #print(">> 모든 원소가 동일한 데이터를 생성합니다.")
    return [42] * length

def generate_with_outliers(length):
    #print(">> 소수의 특이값이 포함된 데이터를 생성합니다.")
    data = [random.randint(0, 1000) for _ in range(length)]
    outlier_count = int(length * 0.01)
    for _ in range(outlier_count):
        index_to_replace = random.randint(0, length - 1)
        data[index_to_replace] = random.randint(900000, 999999)
    return data

def generate_original_random(length):
    #print(">> 완전 무작위 데이터를 생성합니다.")
    return [random.randint(0, 999999) for _ in range(length)]

# --- 자동 실행 ---
if __name__ == "__main__":
    generators = [
        generate_nearly_sorted,
        generate_reverse_sorted,
        generate_with_many_duplicates,
        generate_all_same,
        generate_with_outliers,
        generate_original_random
    ]

    choice = random.randint(0, 5)
    #print(f"🎲 랜덤 선택된 케이스: {choice + 1}")
    data = generators[choice](LENGTH)
    write_to_file(data, FILENAME)
