#!/usr/bin/env python3
import sys

def remove_encryption_flag(input_path: str, output_path: str):
    data = bytearray(open(input_path, "rb").read())
    local_sig   = b"PK\x03\x04"
    central_sig = b"PK\x01\x02"

    def patch_flags(sig: bytes, offset_delta: int):
        idx = 0
        while True:
            idx = data.find(sig, idx)
            if idx == -1:
                break
            flag_off = idx + offset_delta
            # little-endian 2바이트 읽기/쓰기
            flag = int.from_bytes(data[flag_off:flag_off+2], "little")
            new_flag = flag & ~0x0001  # bit0(clear 암호화 플래그)
            data[flag_off:flag_off+2] = new_flag.to_bytes(2, "little")
            idx += len(sig)

    # 로컬 파일 헤더에서 general purpose bit flag (offset +6..+7)
    patch_flags(local_sig,   offset_delta=6)
    # 중앙 디렉터리 파일 헤더에서 general purpose bit flag (offset +8..+9)
    patch_flags(central_sig, offset_delta=8)

    with open(output_path, "wb") as f:
        f.write(data)
    print(f"Encryption flag removed → {output_path}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 strip_zip_password.py 원본.zip 출력.zip")
        sys.exit(1)
    remove_encryption_flag(sys.argv[1], sys.argv[2])
