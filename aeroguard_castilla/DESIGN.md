---
name: AeroGuard Castilla
colors:
  surface: '#05132c'
  surface-dim: '#05132c'
  surface-bright: '#2c3954'
  surface-container-lowest: '#010d27'
  surface-container-low: '#0d1b35'
  surface-container: '#121f39'
  surface-container-high: '#1d2a44'
  surface-container-highest: '#283450'
  on-surface: '#d8e2ff'
  on-surface-variant: '#c9c4d8'
  inverse-surface: '#d8e2ff'
  inverse-on-surface: '#23304b'
  outline: '#938ea1'
  outline-variant: '#484555'
  surface-tint: '#c9bfff'
  primary: '#c9bfff'
  on-primary: '#2f009c'
  primary-container: '#7357f5'
  on-primary-container: '#fdf8ff'
  inverse-primary: '#5e3fdf'
  secondary: '#44dafc'
  on-secondary: '#003640'
  secondary-container: '#00bedf'
  on-secondary-container: '#004856'
  tertiary: '#ffb3ad'
  on-tertiary: '#68000a'
  tertiary-container: '#d73235'
  on-tertiary-container: '#fff8f7'
  error: '#ffb4ab'
  on-error: '#690005'
  error-container: '#93000a'
  on-error-container: '#ffdad6'
  primary-fixed: '#e5deff'
  primary-fixed-dim: '#c9bfff'
  on-primary-fixed: '#1b0063'
  on-primary-fixed-variant: '#461cc7'
  secondary-fixed: '#adecff'
  secondary-fixed-dim: '#40d7f9'
  on-secondary-fixed: '#001f26'
  on-secondary-fixed-variant: '#004e5d'
  tertiary-fixed: '#ffdad7'
  tertiary-fixed-dim: '#ffb3ad'
  on-tertiary-fixed: '#410004'
  on-tertiary-fixed-variant: '#930013'
  background: '#05132c'
  on-background: '#d8e2ff'
  surface-variant: '#283450'
typography:
  display-lg:
    fontFamily: Inter
    fontSize: 40px
    fontWeight: '800'
    lineHeight: 48px
    letterSpacing: -0.03em
  display-lg-mobile:
    fontFamily: Inter
    fontSize: 32px
    fontWeight: '800'
    lineHeight: 40px
    letterSpacing: -0.02em
  headline-lg:
    fontFamily: Inter
    fontSize: 28px
    fontWeight: '700'
    lineHeight: 36px
    letterSpacing: -0.02em
  headline-md:
    fontFamily: Inter
    fontSize: 22px
    fontWeight: '700'
    lineHeight: 30px
    letterSpacing: -0.01em
  headline-sm:
    fontFamily: Inter
    fontSize: 18px
    fontWeight: '600'
    lineHeight: 24px
  body-lg:
    fontFamily: Inter
    fontSize: 16px
    fontWeight: '400'
    lineHeight: 24px
  body-md:
    fontFamily: Inter
    fontSize: 14px
    fontWeight: '400'
    lineHeight: 20px
  body-sm:
    fontFamily: Inter
    fontSize: 12px
    fontWeight: '400'
    lineHeight: 16px
  label-lg:
    fontFamily: Space Grotesk
    fontSize: 14px
    fontWeight: '600'
    lineHeight: 18px
    letterSpacing: 0.04em
  label-md:
    fontFamily: Space Grotesk
    fontSize: 12px
    fontWeight: '600'
    lineHeight: 16px
    letterSpacing: 0.06em
  label-sm:
    fontFamily: Space Grotesk
    fontSize: 10px
    fontWeight: '700'
    lineHeight: 14px
    letterSpacing: 0.08em
rounded:
  sm: 0.25rem
  DEFAULT: 0.5rem
  md: 0.75rem
  lg: 1rem
  xl: 1.5rem
  full: 9999px
spacing:
  gutter: 1rem
  margin: 1rem
  space-xs: 0.25rem
  space-sm: 0.5rem
  space-md: 1rem
  space-lg: 1.5rem
  space-xl: 2rem
---

## Brand & Style

This design system embodies the intersection of tactical defense technology and neighborhood solidarity. Designed for intelligent community surveillance powered by autonomous drone fleets and predictive computer vision, the visual posture must project instantaneous authority, structural reliability, and operational calm. The interface avoids frivolous sci-fi tropes, favoring a restrained, tactical-futurist aesthetic characterized by dark slate depths, luminescent telemetry indicators, and pristine optical balance.

The target audience encompasses neighborhood residents, security committee leaders, and tactical drone operators in the urban sector of Castilla, Bogotá. Every touchpoint instills visceral trust, rapid-response legibility, and high situational awareness under emergency stress. Visual complexity is distilled into high-contrast status cards, precise telemetry vectors, and immediate alert actions.

## Colors

The palette establishes a high-contrast dark environment engineered for nocturnal legibility, rapid telemetry scanning, and clear visual hierarchy during emergency situations.

- **Primary Canvas & Background (`#07152F`):** Deep Navy absorbs ambient visual noise, creating an infinite void optimized for high-contrast alerts and night patrol usage.
- **Surface & Panel Containers (`#102448`):** Midnight Blue provides a lifted, stable base for interactive cards, telemetry feeds, and map sheets.
- **Primary Action & Brand (`#7357F5`):** Vibrant Indigo / Purple delivers a tech-forward signature across primary trigger buttons, navigation focal points, and drone status rings.
- **Secondary Telemetry & Drone Accent (`#20C7E8`):** Electric Neon Cyan communicates active drone tracks, live-stream metadata, operational route lines, and real-time connectivity.
- **Status & Triage System:**
  - **Critical Alert / Emergency (`#EF4444`):** Priority intrusions, immediate SOS dispatches, and geofence breaches.
  - **Warning / Preventative (`#F59E0B`):** Suspicious behavior flags, unverified noise detections, and battery/connection warnings.
  - **Secured / Verified (`#10B981`):** Safe corridors, verified community reports, and nominal patrol status.
- **Text & Content Scales:**
  - High Emphasis: Pure White (`#FFFFFF`) for immediate scannability.
  - Medium Emphasis: Cool Slate (`#CBD5E1`) for telemetry labels, subheaders, and contextual metadata.
  - Low Emphasis: Steel Slate (`#64748B`) for disabled states, timestamps, and subtle coordinate grids.

## Typography

The typographic hierarchy combines the functional legibility of **Inter** for core UI, notifications, and body copy, with the structured, technical character of **Space Grotesk** for tactical telemetry readouts, status badges, timestamps, and drone coordinates.

Key conventions:
- Use all-caps with generous tracking (`0.06em` to `0.08em`) for `label-sm` and `label-md` when rendering telemetry data (e.g., `ALT 42M`, `BAT 89%`, `SEC 04 - CASTILLA`).
- Numeric metrics (speed, response latency, resident count) should use tabular numbers to eliminate jitter during real-time status changes.
- Never mix more than two weights inside a single card component to preserve tactical clarity.

## Layout & Spacing

The layout is built for mobile-first operational environments using a continuous single-column fluid frame (360px–428px viewport width) framed by strict 16px (`1rem`) outer margins.

- **Grid Structure:** A 4-column dynamic grid on mobile devices scales to an 8-column layout on dispatch tablets. Column gutters remain locked at `1rem`.
- **Rhythm & Stacking:** Vertical rhythm adheres strictly to an 8px base grid. Tight relations (badges relative to card titles) use `space-xs` (4px) and `space-sm` (8px). Sibling cards and telemetry panels separate by `space-md` (16px). Major operational modules (e.g., Live Drone View to Community Feed) separate by `space-lg` (24px).
- **Safe Area Insets:** Floating action controls and persistent bottom navigation bars must maintain at least 34px bottom padding on modern gesture devices, offset by an ambient gradient mask to prevent background bleed.

## Shapes

The interface balances military-grade precision with consumer-friendly accessibility by relying on balanced curves:

- **Core Cards & Panels:** Styled with `rounded-2xl` (1rem / 16px radius) to soften complex telemetry displays while maintaining neat modular stacking.
- **Buttons & Tactical Triggers:** 12px border radius for solid interaction confidence.
- **Badges, Status Chips, & Filter Pills:** Full-bleed pill radius (9999px) to isolate critical states from underlying square metrics.
- **Map Floating Widgets:** Fully rounded circles (height = width) for immediate thumb-reachability without directional bias.

## Components

### Buttons & Tactical Triggers
- **Primary Dispatch Button:** Solid `#7357F5` with high-emphasis white text, 12px radius, minimum height 52px for emergency reach. Active state triggers a subtle internal ring `rgba(255, 255, 255, 0.3)` and an outer neon bloom.
- **Emergency SOS Trigger:** Heavy tactile red `#EF4444` pill or square button featuring an ambient pulse animation. Must require a 1.5-second hold interaction with an SVG circular fill animation to prevent accidental dispatches.
- **Secondary Ghost Controls:** Transparent background, 1px border of `rgba(32, 199, 232, 0.4)`, text in `#20C7E8`.

### Status Badges & Pills
- Pill-shaped (`rounded-full`), height 24px, inner padding `0.25rem 0.75rem`.
- Color pairs:
  - Critical: `rgba(239, 68, 68, 0.15)` fill with `#EF4444` text and an active blinking indicator dot.
  - Pending/Preventative: `rgba(245, 158, 11, 0.15)` fill with `#F59E0B` text.
  - Verified Safe: `rgba(16, 185, 129, 0.15)` fill with `#10B981` text.
- Font: `Space Grotesk`, `label-sm`, all caps.

### Cards & Telemetry Displays
- Base background `#102448`, 16px radius, border `1px solid rgba(115, 87, 245, 0.20)`, inner padding 16px.
- Live drone feed cards contain a top camera viewport (16:9 aspect ratio) with an embedded cyan HUD overlay (`#20C7E8`), followed by telemetry metrics below: Sector, Drone ID, Latency, and Battery percentage.

### Input Fields & Search
- Background `#0A1B3A`, border `1px solid rgba(115, 87, 245, 0.25)`, 12px radius.
- Placeholder text in `#64748B`. Focus state shifts the border to `#20C7E8` with a soft outer glow of `0px 0px 8px rgba(32, 199, 232, 0.3)`.

### Checkboxes & Segmented Toggles
- Custom toggle switches feature a deep track `#07152F` with a glowing `#7357F5` thumb that shifts to `#20C7E8` when activating drone autopilot or auto-recording features.

### Floating Bottom Navigation Bar
- Docked or floating 16px above the home indicator, built with frosted glass (`rgba(16, 36, 72, 0.85)` + 16px blur) and an upper hairline of `rgba(115, 87, 245, 0.3)`.
- Features 4 primary destinations: Mapa / Radar (GIS View), Patrullaje (Drone Feed), Alertas (Incidents), and Comunidad (Neighborhood Directory).
- Active icons illuminate in `#20C7E8` with a miniature cyan glow pill beneath the icon.