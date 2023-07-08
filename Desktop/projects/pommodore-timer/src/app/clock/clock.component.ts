import { Component } from '@angular/core';

@Component({
  selector: 'app-clock',
  templateUrl: './clock.component.html',
  styleUrls: ['./clock.component.scss'] // Actualiza la extensión del archivo a '.scss'
})
export class ClockComponent {
  currentTime: Date = new Date();

  constructor() {
    setInterval(() => {
      this.updateTime();
    }, 1000);
  }

  private updateTime(): void {
    this.currentTime = new Date();
  }
}
