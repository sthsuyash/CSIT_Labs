# Operating System

## Programs

1. ### Linux Commands

   The commands used in this lab are listed in the file [linux_commands.md](./1_linux_commands.md).

2. ### Process Creation and Termination

   - [WAP in C to demonstrate the process creation and termination in Linux.](./2_process_creation_and_termination.c)

     ![Click to show](https://user-images.githubusercontent.com/54809836/234344907-62311957-01cd-4f15-937f-74a635a252dc.png)

3. ### Thread Creation and Termination

   - [WAP in C to demonstrate the thread creation and termination in Linux.](./3_thread_creation_and_termination.c)

     ![Click to show](https://user-images.githubusercontent.com/54809836/234344977-fce59f99-67c8-4f92-93da-479316e24e22.png)

4. ### [Simulation of IPC Techniques](./4_IPC_techniques/)

   1. [WAP in C to simulate shared memory concept for IPC](./4_IPC_techniques/a_shared_memory_concept.c)

      ![Click to show](https://user-images.githubusercontent.com/54809836/234344698-b205efd9-b343-4744-a958-320608720ba4.png)

   2. [WAP in C to simulate message passing concept for IPC](./4_IPC_techniques/b_message_passing_concept.c)

      ![Click to show](https://user-images.githubusercontent.com/54809836/234344782-403b4aca-bf1d-4da2-bcb1-7747230f6da3.png)

5. ### [Simulation of Process Scheduling Algorithms](./5_Process_scheduling_algorithms/)

   1. [WAP in C to simulate FCFS CPU Scheduling Algorithm](./5_Process_scheduling_algorithms/a_fcfs.c)
   2. [WAP in C to simulate SJF CPU Scheduling Algorithm](./5_Process_scheduling_algorithms/b_sjf.c)
   3. [WAP in C to simulate SRTF CPU Scheduling Algorithm](./5_Process_scheduling_algorithms/c_srtf.c)
   4. [WAP in C to simulate Round Robin CPU Scheduling Algorithm](./5_Process_scheduling_algorithms/d_round_robin.c)
   5. [WAP in C to simulate Non-Preemptive Priority Scheduling Algorithm](./5_Process_scheduling_algorithms/e_non_preemptive_priority.c)
   6. [WAP in C to simulate Preemptive Priority Scheduling Algorithm](./5_Process_scheduling_algorithms/f_preemptive_priority.c)

6. ### [Simulation of Deadlock Avoidance and Deadlock Detection Algorithms](6_Deadlock_avoidance_and_deadlock_detection_algorithms/)

   (Output screen should contain both positive and negative instances)

   1. WAP to implement Bankers Algorithm for multiple type of resources to decide safe/unsafe state.
   2. WAP for deadlock detection in the system having multiple type of resources. ( The program should list the deadlocked process in case of deadlock detection results true )

7. ### [Simulation of Page Replacement Algorithms](7_Page_replacement_algorithms/)

   1. WAP in C to simulate FIFO Page Replacement Algorithm
   2. WAP in C to simulate Optimal Page Replacement Algorithm
   3. WAP in C to simulate LRU Page Replacement Algorithm
   4. WAP in C to simulate Second Chance Page Replacement Algorithm
   5. WAP in C to simulate LFU Page Replacement Algorithm

8. ### [Simulation of File Allocation Techniques](8_File_allocation_techniques/)

   1. WAP to simulate Contiguous File Allocation Technique
   2. WAP to simulate Linked File Allocation Technique
   3. WAP to simulate File Allocation using File Allocation Table
   4. WAP to implement File Allocation using Inode

9. ### [Simulation of Free Space Management Techniques](9_Free_space_management_techniques/)

   1. WAP to simulate Free Space Management using Bitmaps
   2. WAP to simulate Free Space Management using Linked List

10. ### [Simulation of disk scheduling algorithms](10_Disk_scheduling_algorithms/)

    1. WAP to simulate FCFS Disk Scheduling Algorithm
    2. WAP to simulate SSTF Disk Scheduling Algorithm
    3. WAP to simulate SCAN Disk Scheduling Algorithm
    4. WAP to simulate C-SCAN Disk Scheduling Algorithm
    5. WAP to simulate LOOK Disk Scheduling Algorithm
    6. WAP to simulate C-LOOK Disk Scheduling Algorith

## Folder Structure

```bash
./OS
├── 1_linux_commands.md
|
├── 2_process_creation_and_termination.c
|
├── 3_thread_creation_and_termination.c
|
├── 4_IPC_techniques
│   ├── a_shared_memory_concept.c
│   └── b_message_passing_concept.c
|
├── 5_Process_scheduling_algorithms
│   ├── a_fcfs.c
│   ├── b_sjf.c
│   ├── c_srtf.c
│   ├── d_round_robin.c
│   ├── e_non_preemptive_priority.c
│   └── f_preemptive_priority.c
|
├── 6_Deadlock_avoidance_and_deadlock_detection_algorithms
│   ├── a_bankers_algorithm.c
│   └── b_deadlock_detection.c
|
├── 7_Page_replacement_algorithms
│   ├── a_fifo.c
│   ├── b_optimal.c
│   ├── c_lru.c
│   ├── d_second_chance.c
│   └── e_lfu.c
|
├── 8_File_allocation_techniques
│   ├── a_contiguous.c
│   ├── b_linked.c
│   ├── c_fat.c
│   └── d_inode.c
|
├── 9_Free_space_management_techniques
│   ├── a_bitmap.c
│   └── b_linked_list.c
|
├── 10_Disk_scheduling_algorithms
│   ├── a_fcfs.c
│   └── b_sstf.c
│   └── c_scan.c
│   └── d_cscan.c
│   └── e_look.c
│   └── f_clook.c
.
```
