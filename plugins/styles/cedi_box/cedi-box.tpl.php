<?php
/**
 * @file
 * This template handles the layout of oa_pane style.
 */
?>
<div class="cedi-pane <?php if (isset($settings['extra_class'])): print $settings['extra_class']; endif; ?>">
  <?php print $content; ?>
</div>
