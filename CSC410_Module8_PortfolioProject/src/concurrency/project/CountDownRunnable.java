package concurrency.project;

public class CountDownRunnable implements Runnable {
	@Override
	public void run() {
		for (int i = 20; i >= 0; i--) {
			System.out.println(Thread.currentThread().getName() + ": " + i);
			try {
				Thread.sleep(100); //Introduce delay
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}

