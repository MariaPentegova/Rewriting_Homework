import heapq
import pickle

def build_huffman_tree(text: str):
    freq = {}
    for ch in text:
        freq[ch] = freq.get(ch, 0) + 1
    heap = [[weight, [char, '']] for char, weight in freq.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    if heap:
        return dict(sorted(heap[0][1:], key=lambda p: p[0]))
    else:
        return {}

def generate_table(message: str) -> dict:
    return build_huffman_tree(message)

def encode(message: str) -> tuple[str, dict]:
    table = generate_table(message)
    encoded_message = ''.join([table[ch] for ch in message])
    return encoded_message, table

def decode(encoded_str: str, table: dict) -> str:
    reversed_table = {v: k for k, v in table.items()}
    current_code = ''
    decoded_message = ''
    for bit in encoded_str:
        current_code += bit
        if current_code in reversed_table:
            decoded_message += reversed_table[current_code]
            current_code = ''
    return decoded_message

def save_to_file(filepath: str, message: str):
    encoded_str, table = encode(message)
    
    # сериализация таблицы
    table_bytes = pickle.dumps(table)
    table_size = len(table_bytes)
    
    # padding for byte alignment
    padding_size = (8 - len(encoded_str) % 8) % 8
    encoded_str_padded = encoded_str + '0' * padding_size
    
    # строка в байты
    byte_array = bytearray()
    for i in range(0, len(encoded_str_padded), 8):
        byte = encoded_str_padded[i:i+8]
        byte_array.append(int(byte, 2))
    
    with open(filepath, 'wb') as f:
        f.write(table_size.to_bytes(4, byteorder='big'))
        f.write(table_bytes)
        f.write(padding_size.to_bytes(1, byteorder='big'))
        f.write(byte_array)

def load_from_file(filepath: str) -> str:
    with open(filepath, 'rb') as f:
        table_size_bytes = f.read(4)
        table_size = int.from_bytes(table_size_bytes, byteorder='big')
        table_bytes = f.read(table_size)
        table = pickle.loads(table_bytes)
        padding_size = int.from_bytes(f.read(1), byteorder='big')
        message_bytes = f.read()
        bits_str = ''.join([format(byte, '08b') for byte in message_bytes])
        if padding_size > 0:
            bits_str = bits_str[:-padding_size]
        return decode(bits_str, table)

# Пример использования:
# сохранить в файл
# save_to_file('huffman.bin', 'Ваш текст для сжатия')

# загрузить и расшифровать
# original_text = load_from_file('huffman.bin')
# print(original_text)
