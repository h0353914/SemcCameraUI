from adb import Adb

# 預設 SO 檔案路徑
SO = {
    "system/lib/libcacao_process_ctrl_gateway.so",
    "system/lib/libcacao_process_ctrl_gateway_real.so",
}


def compare_device_so(so_path, devices):
    sha1 = {}
    for serial in devices:
        adb = Adb(serial=serial)
        sha1_value = adb.sha1sum(so_path)
        if sha1_value == "":
            sha1_value = "N/A"

        if sha1_value not in sha1:
            sha1[sha1_value] = []
        sha1[sha1_value].append(serial)
    return sha1


def print_sha1(sha1):
    for sha1_value, serials in sha1.items():
        print(f"\tSHA1: {sha1_value}")
        print(f"\tDevices: {', '.join(serials)}")
        print( "","-" * 40)


def main() -> None:
    devices = Adb().devices()
    for so in SO:
        print()
        print(so)
        sha1 = compare_device_so(so, devices)
        print_sha1(sha1)


if __name__ == "__main__":
    main()
