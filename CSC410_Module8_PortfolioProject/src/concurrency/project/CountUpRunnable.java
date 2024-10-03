package concurrency.project;

public class CountUpRunnable  implements Runnable{
	@Override
	public void run() {
		for (int i = 0; i <= 20; i++) {
			System.out.println(Thread.currentThread().getName() + ": " + i);
			try {
				Thread.sleep(100); //Introduce delay
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
