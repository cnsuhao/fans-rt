;=========================================================================================================================
;�� �� ��:  boot.inc
;��    ��:  ����
;�� �� ��:  ��
;��������:  fat32.s/fat16.s/fat12.s
;��    ��:
;           2005-11-05            ����              �����ļ�
%ifndef __KERNEL_BOOT_INC
%define __KERNEL_BOOT_INC
;==========================================================================================================================
; boot sector ��ַ�������
SECTOR_SIZE             EQU             0x0200                  ; ÿ�����ֽ���
SECTOR_READER           EQU             0x0201                  ; �����̵������
LOADER_SEGBASE          EQU             0x5000                  ; LOADER ���ص�ַ
PROTAL_SEGBASE          EQU             0x40000                 ; ��ڶε�ַ
OFFSET_SECTOR           EQU             0x7c00                  ; ����������ƫ�Ƶ�ַ
OFFSET_BSFLAG           EQU             0x01fc                  ; ����������־ƫ�Ƶ�ַ
DVALUE_BSFLAG           EQU             0xaa55                  ; ����������־��
DVALUE_FAFLAG           EQU             0x4146                  ; 'FA' ������־
FITEM_LENGTH            EQU             0x0020                  ; �ļ��Ǽ����
FAT_OFFSET_BLOCKID_L    EQU             0x001a                  ; �ļ��غ�����ļ��Ǽ����ƫ�Ƶ�ַ
FAT_OFFSET_BLOCKID_H    EQU             0x0012                  ; �ļ��غ�����ļ��Ǽ����ƫ�Ƶ�ַ
FAT_OFFSET_FILESIZE     EQU             0x001c                  ; �ļ��ĳ���
ERETRY_COUNT            EQU             0x0005                  ; ������������Դ���
;==========================================================================================================================
; ELF �ļ���ض���
ELFHDR_OFFSET_SHOFF     EQU             0x20                    ; Elf32_Ehdr->shoff ��ƫ�Ƶ�ַ
ELFHDR_OFFSET_SHNUM     EQU             0x30                    ; Elf32_Ehdr->shnum ��ƫ�Ƶ�ַ
SECHDR_OFFSET_MMADDR    EQU             0x0c                    ; Elf32_Shdr->sh_addr ��ƫ�Ƶ�ַ
SECHDR_OFFSET_OFFSET    EQU             0x10                    ; Elf32_Shdr->offset ��ƫ�Ƶ�ַ
SIZEOF_SECHDR           EQU             0X28                    ; Elf32_Shdr �ĳ���
;==========================================================================================================================
; FAT �غŶ���
FAT32_TAIL              EQU             0x0fffffff              ; FAT32 �ļ��������־
FAT16_TAIL              EQU             0xffff                  ; FAT16 �ļ��������־
FAT12_TAIL              EQU             0x0fff                  ; FAT12 �ļ��������־
;==========================================================================================================================
; LOADER �ļ���ʽ����
BINLOADER               EQU             0                       ; װ��� loader �ļ�Ϊ bin �ļ�
ELFLOADER               EQU             1                       ; װ��� loader �ļ�Ϊ elf �ļ�
MZLOADER                EQU             2                       ; װ��� loader �ļ�Ϊ mz �ļ�

%define         LOADER_FNAME                    'LOADER     '   ; ��Ҫ���ص��ļ���
%strlen         FNAME_LENGTH                    LOADER_FNAME

%endif